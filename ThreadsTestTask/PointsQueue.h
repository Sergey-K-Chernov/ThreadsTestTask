#pragma once
#include <queue>
#include <shared_mutex>
#include <optional>

#include "Geopoint.h"

typedef std::pair<Geopoint, Geopoint> PointPair;

class PointsQueue
{
public:
	PointsQueue() {}
	~PointsQueue() {}

	bool empty() const;
	const std::optional<PointPair> get() const;
	void push(PointPair&& data);
	void pop();

private:
	std::queue<PointPair, std::deque<PointPair>> queue;

	mutable std::shared_mutex mutex;
};
