/*
 *  Copyright (C) 2021 mod.io Pty Ltd. <https://mod.io>
 *
 *  This file is part of the mod.io SDK.
 *
 *  Distributed under the MIT License. (See accompanying file LICENSE or
 *   view online at <https://github.com/modio/modio-sdk/blob/main/LICENSE>)
 *
 */

#ifdef MODIO_SEPARATE_COMPILATION
	#include "modio/detail/ModioObjectTrack.h"
#else
	#pragma once
#endif

#include "modio/core/ModioLogger.h"

namespace Modio
{
	namespace Detail
	{

	OperationTracker& OperationTracker::operator=(OperationTracker&& Other)
	{
		OpName = Other.OpName;
		Other.bMovedFrom = true;
		return *this;
	}

	OperationTracker::~OperationTracker() 
	{
		if (!bMovedFrom)
		{
			OperationMap().erase(OpPtr);
		}
	}


#if MODIO_TRACK_OPS
		template<typename Base>
		BaseOperation<Base>::BaseOperation()
		{
			++BaseOperation<Base>::Count;

			char output[512];
			sprintf(output, "%s %d\n", __FUNCTION__, Count);
			OutputDebugStringA(output);
		}

		template<typename Base>
		BaseOperation<Base>::BaseOperation(BaseOperation<Base>&& Other)
		{
			Other.bMovedFrom = true;
		}

		template<typename Base>
		BaseOperation<Base>::~BaseOperation()
		{
			if (bMovedFrom)
			{
				return;
			}

			--BaseOperation<Base>::Count;

			char output[512];
			sprintf(output, "%s %d\n", __FUNCTION__, Count);
			OutputDebugStringA(output);
		}
#endif
#if MODIO_SEPARATE_COMPILATION
		bool BaseOperationCommonImpl::RequiresShutdown = false;
#endif
	} // namespace Detail
} // namespace Modio
