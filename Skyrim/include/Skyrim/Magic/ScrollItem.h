#pragma once

#include "SpellItem.h"
#include "../FormComponents/TESModelTextureSwap.h"
#include "../FormComponents/BGSDestructibleObjectForm.h"
#include "../FormComponents/BGSPickupPutdownSounds.h"
#include "../FormComponents/TESWeightForm.h"
#include "../FormComponents/TESValueForm.h"

/*==============================================================================
class ScrollItem +0000 (_vtbl=01078AFC)
0000: class ScrollItem
0000: |   class SpellItem
0000: |   |   class MagicItem
0000: |   |   |   class TESBoundObject
0000: |   |   |   |   class TESObject
0000: |   |   |   |   |   class TESForm
0000: |   |   |   |   |   |   class BaseFormComponent
0020: |   |   |   class TESFullName
0020: |   |   |   |   class BaseFormComponent
0028: |   |   |   class BGSKeywordForm
0028: |   |   |   |   class BaseFormComponent
0050: |   |   class BGSEquipType
0050: |   |   |   class BaseFormComponent
0058: |   |   class BGSMenuDisplayObject
0058: |   |   |   class BaseFormComponent
0060: |   |   class TESDescription
0060: |   |   |   class BaseFormComponent
0090: |   class TESModelTextureSwap
0090: |   |   class TESModel
0090: |   |   |   class BaseFormComponent
00AC: |   class BGSDestructibleObjectForm
00AC: |   |   class BaseFormComponent
00B4: |   class BGSPickupPutdownSounds
00B4: |   |   class BaseFormComponent
00C0: |   class TESWeightForm
00C0: |   |   class BaseFormComponent
00C8: |   class TESValueForm
00C8: |   |   class BaseFormComponent
==============================================================================*/
// D0
class ScrollItem : public SpellItem,
	public TESModelTextureSwap,			// 90
	public BGSDestructibleObjectForm,	// AC
	public BGSPickupPutdownSounds,		// B4
	public TESWeightForm,				// C0
	public TESValueForm					// C8
{
public:
	enum { kTypeID = (UInt32)FormType::ScrollItem };

	virtual ~ScrollItem();								// 00409370

	// @override
	virtual UInt32	GetMagicType(void) const override;			// 54 0055BEC0 { return kType_Scroll; }
	virtual UInt32	GetCastingType(void) const override;		// 56 00CAC8A0 { return kCastType_FireAndForget; }
	virtual bool	Unk_61(UInt32 arg) override;				// 61 004091A0 { return false; }
	virtual SInt32	GetActorValueType(void) const override;		// 67 00407240 { return -1; }
	virtual void	Unk_6B(TESFile *file, UInt32 subtype);		// 6B 00409480
};
STATIC_ASSERT(sizeof(ScrollItem) == 0xD0);
