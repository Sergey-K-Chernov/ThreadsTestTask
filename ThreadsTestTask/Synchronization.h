#pragma once
#include <mutex>
#include <condition_variable>

// ����� ������������� ���������, ����� ���������� 
// �� ���� ����������� ������ � "�������" �����, � �������� �� �������
struct SynchronizationData {
	std::mutex mutex;
	std::condition_variable cv;
	bool got_next = false;
};