#ifndef CSNAKE_FILESYSTEM_H

class FileSystem
{
public:
	static FileSystem& instance();
	virtual char* read(const char* path) = 0;
	virtual void write(const char* path,const char* text) = 0;
	virtual ~FileSystem(){}
protected:
	FileSystem(){}
};

class PS3FileSystem :public FileSystem {
public:
	virtual char* read(const char* path) override {
		// Use Sony file IO API
		return "PS3FileSystem";
	}
	virtual void write(const char* path, const char* text) override {
		// Use Sony file IO API
	}
};

class WiiFileSystem :public FileSystem {
public:
	virtual char* read(const char* path) override {
		// Use Nintendo file IO API
		return "WiiFileSystem";
	}
	virtual void write(const char* path, const char* text) override {
		// Use Nintendo file IO API
	}
};

#define PLAYSTATION3 1
#define WII 2

#define PLATFROM PLAYSTATION3


#endif // !CSNAKE_FILESYSTEM_H

