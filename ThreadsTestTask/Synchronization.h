#pragma once
#include <mutex>
#include <condition_variable>

// явна€ синхронизаци€ требуетс€, чтобы обработчик 
// не ждал поступлени€ данных в "гор€чем" цикле, а дергалс€ по команде
struct SynchronizationData {
	std::mutex mutex;
	std::condition_variable cv;
	bool got_next = false;
};