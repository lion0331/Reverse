#include "pch.h"
#include "framework.h"
#include "Thread.h"
#include <thread>



using namespace edoyun;

edoyun::CThread::CThread() :m_pFunction(NULL)
{
	m_bValid = false;
	m_hThread = CreateThread(
		NULL, 0, CThread::ThreadEntry,
		this, CREATE_SUSPENDED, &m_nThreadID);
}

edoyun::CThread::~CThread()
{
	Stop();
	CFunctionBase* func = m_pFunction;
	m_pFunction = NULL;
	delete func;
}

int edoyun::CThread::Start()
{
	if (m_pFunction == NULL) {
		return THREAD_IS_INVALID;
	}
	if ((m_hThread != NULL) && (m_bValid == false)) {
		DWORD ret = ResumeThread(m_hThread);
		if (ret == -1) {
			return ret;
		}
	}
	return THREAD_OK;
}

int edoyun::CThread::Pause()
{
	if ((m_hThread != NULL) && (m_bValid == true)) {
		DWORD ret = SuspendThread(m_hThread);
		if (ret == -1) {
			return THREAD_PAUSE_ERROR;
		}
	}
	else {//�߳���Ч
		return THREAD_IS_INVALID;
	}
	return THREAD_OK;
}

int edoyun::CThread::Stop()
{
	m_bValid = false;//��Ʊ�־
	if (m_hThread != NULL) {
		//������ʱ��û�н�������ǿ�ƽ����߳�
		DWORD ret = WaitForSingleObject(m_hThread, 10);
		if (ret == WAIT_TIMEOUT) {
			//������Ҫ�ߵ���һ�������������߳���new�������ڴ潫ʧ�أ�����
			TerminateThread(m_hThread, THREAD_IS_BUSY);
		}
		CloseHandle(m_hThread);
		m_hThread = NULL;
	}
	return THREAD_OK;
}

int edoyun::CThread::Restart()
{
	if (m_pFunction == NULL) {//�Զ��庯����Ч
		return THREAD_IS_INVALID;
	}
	if (m_bValid != false || (m_hThread != NULL)) {
		//�߳���Ȼ������
		return THREAD_IS_BUSY;
	}
	m_hThread = CreateThread(
		NULL, 0, CThread::ThreadEntry,
		this, 0, &m_nThreadID);
	return THREAD_OK;
}

bool edoyun::CThread::isValid() const
{
	return m_bValid && (m_pFunction != NULL);
}

DWORD WINAPI edoyun::CThread::ThreadEntry(LPVOID lpParam)
{
	CThread* thiz = (CThread*)lpParam;
	thiz->EnterThread();
	ExitThread(THREAD_OK);
	return THREAD_OK;
}

void edoyun::CThread::EnterThread()
{
	int ret = 0;
	m_bValid = true;
	do {
		while (m_pFunction == NULL) {
			if (m_bValid == false)return;
			Sleep(1);
		}
		CFunctionBase* func = m_pFunction;
		if (func == NULL)break;
		ret = (*func)();
		TRACE(_T("ret=%d\r\n"), ret);
	} while (ret == THREAD_AGAIN);
	m_bValid = false;
}

