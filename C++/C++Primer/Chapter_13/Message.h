#ifndef PRIMER_MESSAGE_H
#define PRIMER_MESSAGE_H

#include <set>
#include <string>

class Message
{
	friend class Folder;
public:
	explicit Message(const std::string &str = "") : m_msg(str) {}
	Message(const Message &rhs);
	Message &operator=(const Message &rhs);
	~Message();

	void Save(Folder &s_f);
	void Remove(Folder &r_f);

private:
	std::string m_msg;
	std::set<Folder*> m_folders;
};

#endif //PRIMER_MESSAGE_H
