/*
Implement a logger class using singleton design pattern.
This logger class should be thread safe i.e when the logger
class is used in multi threaded environment it should abide by
its principal.The logger class functionality is to print log statements with current date and time
*/
#include<bits/stdc++.h>
using namespace std;
mutex mtx;
class Logger{
	private:
		Logger() {}
		Logger(const Logger&) = delete;
		Logger& operator=(const Logger&) = delete;
		static Logger& getInstance(){
			static Logger logger;
			return logger;
		}
		
		template<typename... Args>
		static void log(const char* msg1,const char* msg, Args... args){
			time_t now = time(0);
			char* dt = ctime(&now);
			mtx.lock();
			printf("%s\t",dt);
			printf(msg1);
			printf(msg, args...);
			printf("\n\n");
			mtx.unlock();
		}
		
	public:
		template<typename... Args>
		static void Error(const char* msg, Args... args){
			getInstance().log("[Error]\t", msg, args...);
		}
		template<typename... Args>
		static void Debug(const char* msg,Args... args){
			getInstance().log("[Debug]\t", msg, args...);
		}
		template<typename... Args>
		static void Trace(const char* msg,Args... args){
			getInstance().log("[Trace]\t", msg, args...);
		}
		~Logger() {}
};

void log_test(int n){
	Logger::Trace("%d",n);
}
int main(){
	Logger::Debug("hello");
	Logger::Error("Hello");
	
	thread threads[10];
	for(int i=0;i<10;i++)
		threads[i]=thread(log_test,i);
}
