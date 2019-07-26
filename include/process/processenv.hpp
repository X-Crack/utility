#pragma once
#ifndef _PROCESSENV_H_
#define _PROCESSENV_H_
#include <misc_config.h>
#include <vector>
#include <psapi.h>
#include <TlHelp32.h>
namespace Cry
{
	struct MISC_EXPORTS CloseHandleEx
	{
	public:
		explicit CloseHandleEx(const Handle& hHandle)
		{
			m_hHandle = hHandle;
		};
		~CloseHandleEx() { CloseHandle(m_hHandle); };
	private:
		Handle					m_hHandle;
	};

	class MISC_EXPORTS ProcessHelper
	{
	public:
		explicit ProcessHelper() {};
	public:
		// 获取自身进程的命令行
		bool CommandLineArgs(const std::xstring& CommandLine, std::vector<std::xstring>&& v);
		// 获取进程句柄
		inline Handle GetProcessHandle(uint32 Index, uint32 dwDesiredAccess = PROCESS_ALL_ACCESS, uint32 bInheritHandle = 0) const;
	public:
		// 获取进程完整路径
		bool GetDirectory(String ResultString[256], const std::xstring& lpWindowName, const std::xstring& lpClassName = std::xstring(), const std::xstring& lpszProcessName = std::xstring()) const;
		bool GetDirectory(String ResultString[256], const std::xstring& lpszProcessName, uint32 th32ProcessID = 0);
	public:
		// 根据窗口标题或类名获取进程ProcessIndex
		uint32 GetProcessIndex(const std::xstring& lpWindowName, const std::xstring& lpClassName, const std::xstring& lpszProcessName = std::xstring()) const;
		// 根据系统快照查找进程名获取进程ProcessIndex
		uint32 GetProcessIndex(const std::xstring& lpszProcessName, uint32 dwFlags = TH32CS_SNAPPROCESS, uint32 th32ProcessID = 0) const;
	private:
		bool GetDirectory(uint32 Index, PString ResultString, ulong StrSize = 256) const;
	};
}
#endif