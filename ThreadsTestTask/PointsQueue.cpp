#include "PointsQueue.h"


bool PointsQueue::empty() const
{
	return queue.empty();
}

const std::optional<PointPair> PointsQueue::get() const
{
	if (queue.empty())
	{
		return std::nullopt;
	}
	std::shared_lock<std::shared_mutex> lock(mutex);
	return queue.front();
}


void PointsQueue::push(PointPair&& data)
{
	std::unique_lock<std::shared_mutex> lock(mutex);
	queue.push(data);
}


void PointsQueue::pop()
{
	std::unique_lock<std::shared_mutex> lock(mutex);
	queue.pop();
}