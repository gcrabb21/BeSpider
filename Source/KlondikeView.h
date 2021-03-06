/*
 * Copyright 2013-2014 Przemysław Buczkowski <przemub@przemub.pl>
 * All rights reserved. Distributed under the terms of the MIT license.
 */
#ifndef _KLONDIKEVIEW_H_
#define _KLONDIKEVIEW_H_


#include <Bitmap.h>
#include <Entry.h>
#include <FileGameSound.h>
#include <Point.h>
#include <Rect.h>
#include <Menu.h>
#include <Resources.h>
#include <SimpleGameSound.h>
#include <View.h>

#include "Solitare.h"
#include "SolitareView.h"

const int32 kNewGameMessage = 'NewG';
const int32 kCheatMessage = 'Chtr';
const int32 kAutoPlayMessage = 'Auto';
const int32 kAutoPlayEnableMessage = 'EAut';
const int32 kQuickAutoPlayMessage = 'QAut';

#define KLONDIKE_CARDS_IN_PLAY CARDS_IN_DECK

class KlondikeView : public SolitareView {
public:
								KlondikeView();
								~KlondikeView();

	virtual	void				AllAttached();
	virtual	void				Draw(BRect rect);
	virtual	void				Pulse();
	virtual	void				MouseDown(BPoint point);
	virtual	void				MouseUp(BPoint point);
	virtual BMenu*				GetOptionMenu();
	virtual void				ReciveOptionMessage(BMessage* message);

	virtual void				NewGame();
	
	virtual	void				Resize(float newWidth, float newHeight);


private:
			BSimpleGameSound*	_LoadSound(const char* resourceName);
			void				_LoadBitmaps();
			void				_GenerateBoard();
			bool				_MoveWasteToFoundation();
			int					_CardHSpacing();
			void				Cheat();
			void				CheckBoard();
			bool				MoveOneToFoundation(short stack = 0,
									short endStack = 6);
									
			bool				fAutoPlayStarted;
			
			BBitmap*			fCards[CARDS_IN_DECK];
			BBitmap*			fBack[CACHED_BACKS];
			BBitmap*			fEmpty;

			BResources*			fResources;
			BSimpleGameSound*	fShuffle;
			BSimpleGameSound*	fFanfare;

			int					windowWidth;
			int					windowHeight;

			card*				fStock[24];
			short				fWasteCard;
			bool				fIsWasteCardPicked;
			short				fFoundations[4];
			short				fFoundationsColors[4];
			bool				fIsFoundationCardPicked;
			
			bool				fWon;
			short				fPickedCardBoardPos;
				// pile picked card is from
			card*				fPickedCard;
			bool				fIsCardPicked;
			bool				fMouseLock;

			bool				fAutoPlayEnabled;
			bool				fQuickAutoPlay;
			short				fDoubleClick;
			short				fAutoPlayCountdown;

			BMenuItem*		fAutoPlayEnabledItem;
			BMenuItem*		fQuickAutoPlayItem;

			int					fPoints;
			Solitare solitare;
};


#endif // _KLONDIKEVIEW_H_
