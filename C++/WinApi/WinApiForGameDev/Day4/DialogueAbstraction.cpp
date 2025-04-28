#include <Windows.h>
#include <iostream>
#include <commdlg.h>

enum FileType
{
	none = 0,
	txt,
	png,
	jpg
};

class DialogueUtility
{
public:
	DialogueUtility(FileType type) : m_type(type) {};
	virtual ~DialogueUtility() {}
protected:
	FileType m_type;
public:
	bool OpenDialogue(std::string title)
	{
		bool result = false;
		LPCSTR cstr = title.c_str();

		OPENFILENAMEA file = { sizeof(OPENFILENAMEA) };
		file.lpstrTitle = cstr;
		file.lpstrFilter = SetFillter();
		file.lpstrInitialDir = ""; // ����ȭ������ �ʱ� ���丮 ����

		// buffer
		char buff[MAX_PATH] = {};
		file.nMaxFile = sizeof(buff);	// lpstrFile�� ����Ű�� ������ ũ��E
		file.lpstrFile = buff;

		return GetOpenFileNameA(&file);
	}
protected:
	LPCSTR SetFillter()
	{
		LPCSTR result = "\0";

		switch (m_type)
		{
		case FileType::none:
			result = "All Files\0.*\0\0";
			break;
		case FileType::jpg:
			result = "jpg files\0*.jpg";
			break;
		case FileType::png:
			result = "png files\0*.png";
			break;
		case FileType::txt:
			result = "txt files\0*.txt";
			break;
		}

		return result;
	}
};

int main()
{
	FileType type = FileType::txt;

	DialogueUtility dialogue = DialogueUtility(type);

	std::cout << dialogue.OpenDialogue("Ŭ���� �׽�Ʈ");
}