#pragma once

#include "NiTMapBase.h"
#include "NiTDefaultAllocator.h"

// 10
template <typename T_key, typename T_data>
class NiTMap
{
public:
	virtual ~NiTMap();

	struct NiTMapItem
	{
		NiTMapItem* next;
		T_key		key;
		T_data		data;
	};

	T_data	Get(T_key key)
	{
		UInt32	bucket = GetBucket(key);

		for (NiTMapItem* iter = buckets[bucket]; iter; iter = iter->next)
		{
			if (Compare(iter->key, key))
			{
				return iter->data;
			}
		}

		return T_data();
	}

	virtual UInt32	GetBucket(T_key key);					// return hash % numBuckets;
	virtual bool	Compare(T_key lhs, T_key rhs);			// return lhs == rhs;
	virtual void	FillItem(NiTMapItem* item, T_key key, T_data data);
	// item->key = key; item->data = data;
	virtual void	Fn_04(UInt32 arg);	// nop
	virtual NiTMapItem* AllocItem(void);				// return new NiTMapItem;
	virtual void	FreeItem(NiTMapItem* item);			// item->data = 0; delete item;

//	void		** _vtbl;	// 00
	UInt32		numBuckets;	// 04
	NiTMapItem** buckets;	// 08
	UInt32		numEntries;	// 0C
};
