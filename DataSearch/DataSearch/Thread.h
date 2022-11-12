#pragma once
#include <Windows.h>
#include <functional>
#include <memory>
#include <atomic>

namespace edoyun {
	class CFunctionBase
	{
	public:
		virtual ~CFunctionBase() = default;
		virtual int operator()() = 0;
	};

	template <class _FX, class... _Types>
	class CFunction :public CFunctionBase
	{
	public:
		CFunction(_FX _Func, _Types... _Args)
			:m_binder(std::forward<_FX>(_Func), std::forward<_Types>(_Args)...)
		{}
		virtual ~CFunction() {}
		virtual int operator()() {
			return m_binder();
		}
		std::_Binder<std::_Unforced, _FX, _Types...> m_binder;
	};
	enum CThreadStatus
	{
		THREAD_AGAIN = 1,			//�߳��ٴ�����
		THREAD_OK = 0,				//�߳�Ŀǰһ������
		THREAD_IS_INVALID = -1,		//�߳���Ч
		THREAD_PAUSE_ERROR = -2,	//�߳���ͣ����
		THREAD_IS_BUSY = -3,		//�߳�ռ�ߣ���ǿ�ƽ���
	};

	class CThread
	{
	public://std::bind
		template< typename _FX, typename... _Types >
		CThread(_FX _Func, _Types... _Args) :m_pFunction(new CFunction<_FX, _Types...>(_Func, _Args...))
		{
			m_bValid = false;
			m_hThread = CreateThread(
				NULL, 0, CThread::ThreadEntry,
				this, CREATE_SUSPENDED, &m_nThreadID);
		}
		CThread();
		~CThread();
		//��ֹ���ƣ�����
		CThread(const CThread&) = delete;
		CThread& operator=(const CThread&) = delete;
		int Start();//��ʼ/�ָ�
		int Pause();//��ͣ
		int Stop();//ֹͣ
		int Restart();//�����̣߳���һ�����б��������
		bool isValid() const;
		template< typename _FX, typename... _Types >
		int SetThreadFunc(_FX _Func, _Types... _Args) {
			if (_Func == NULL) {
				m_pFunction = NULL;
			}
			else {
				m_pFunction = new CFunction<_FX, _Types...>(_Func, _Args...);
			}
			return 0;
		}
	private:
		static DWORD WINAPI ThreadEntry(LPVOID lpParam);
		void EnterThread();//__thiscall
	private:
		DWORD m_nThreadID;
		HANDLE m_hThread;
		bool m_bValid;//True��ʾ�߳����� False��ʾ�̲߳�����
		std::atomic<CFunctionBase*> m_pFunction;
	};
}
