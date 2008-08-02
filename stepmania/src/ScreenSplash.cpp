#include "global.h"
#include "ScreenSplash.h"
#include "ThemeManager.h"
#include "RageUtil.h"
#include "ScreenManager.h"

AutoScreenMessage( SM_PrepNextScreen )


REGISTER_SCREEN_CLASS( ScreenSplash );

void ScreenSplash::Init()
{
	ALLOW_START_TO_SKIP.Load( m_sName, "AllowStartToSkip" );
	PREPARE_SCREEN.Load( m_sName, "PrepareScreen" );

	ScreenWithMenuElements::Init();
}

void ScreenSplash::BeginScreen()
{
	ScreenWithMenuElements::BeginScreen();
}

void ScreenSplash::HandleScreenMessage( const ScreenMessage SM )
{
	if( SM == SM_DoneFadingIn )
	{
		if( PREPARE_SCREEN )
			SCREENMAN->PrepareScreen( GetNextScreenName() );
	}
	else if( SM == SM_MenuTimer )
	{
		StartTransitioningScreen( SM_GoToNextScreen );
	}

	ScreenWithMenuElements::HandleScreenMessage( SM );
}

void ScreenSplash::MenuBack( const InputEventPlus &input )
{
	if( IsTransitioning() )
		return;
	Cancel( SM_GoToPrevScreen );
}

void ScreenSplash::MenuStart( const InputEventPlus &input )
{
	if( IsTransitioning() )
		return;
	if( !ALLOW_START_TO_SKIP )
		return;
	StartTransitioningScreen( SM_GoToNextScreen );
}

/*
 * (c) 2001-2004 Chris Danford
 * All rights reserved.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, and/or sell copies of the Software, and to permit persons to
 * whom the Software is furnished to do so, provided that the above
 * copyright notice(s) and this permission notice appear in all copies of
 * the Software and that both the above copyright notice(s) and this
 * permission notice appear in supporting documentation.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF
 * THIRD PARTY RIGHTS. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR HOLDERS
 * INCLUDED IN THIS NOTICE BE LIABLE FOR ANY CLAIM, OR ANY SPECIAL INDIRECT
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
 * OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */
