#ifndef __SYLAR_LOG_H__
#define __SYLAR_LOG_H__

#include <string>
#include <stdint.h>
#include <memory> 

namespace sylar {

// Log Event
class LogEvent {
public:
	typedef std::shared_ptr<LogEvent> ptr;
	LogEvent();

private:
	const char* m_file = nullptr; // File Name
	uint32_t m_line = 0;          // Line Number
	uint32_t m_elapse = 0;        // The Millisecond from the program starts to now 
	uint32_t m_threadId = 0;      // Thread Id
	uint32_t m_fiberId = 0;		  // Fiber Id
	uint64_t m_time;              // Time Stamp
	std::string m_content;
};

// Log Level
class LogLevel {
public:
 	enum {
		DEBUG = 1;
		INFO = 2;
		WARN = 3;
		ERROR = 4;
		FATAL = 5
	};
};


// Log Output Place
class LogAppender {
public:
	typedef std::shared_ptr<LogAppender> ptr;
	virtual ~LogAppender() {}

	void log(LogLevel::Level level, LogEvent::ptr event);
private:
	LogLevel::Level m_level;
}

// Log Formatter
class LogFormatter {
public:
	typedef std::shared_ptr<LogFormatter> ptr;

	std::string format(LogEvent::ptr event);	
private:
}

// Log Output
class Logger{
public:
	// Log Level, Class
	typedef std::shared_ptr<Logger> ptr;

	Logger(const std::string& name = "root");
	void log(LogLevel::Level level, LogEvent::ptr event);
private:
	std::string m_name;
	LogLevel::Level m_level;
	LogAppender::ptr
};

// Output To Terminal Appender
class StdOutLogAppender : public LogAppender

};

// Output To A File Appender
class FileLogAppender : public LogAppender
{

};



#endif
