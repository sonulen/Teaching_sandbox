/*
 * smart_mutex_lock.h
 */

#ifndef FEATURES_SMART_MUTEX_LOCK_H_
#define FEATURES_SMART_MUTEX_LOCK_H_

#include <mutex>
namespace Other_feature {
class Lock {
public:
	explicit Lock (std::mutex& mutex): ref_mutex(mutex) {
		this->ref_mutex.lock;
	};

	Lock(const Lock& rhs) = delete;
	Lock(const Lock&& rhs) = delete;
	Lock& operator= (const Lock& v) = delete;

	~Lock() {
		this->ref_mutex.unlock;
	}
private:
	std::mutex& ref_mutex;
};
}


#endif /* FEATURES_SMART_MUTEX_LOCK_H_ */
