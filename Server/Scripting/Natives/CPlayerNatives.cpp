//========== IV:Multiplayer - https://github.com/IVMultiplayer/IVMultiplayer ==========
//
// File: CPlayerNatives.cpp
// Project: Server.Core
// Author: xForce <xf0rc3.11@gmail.com>
// License: See LICENSE in root directory
//
//==============================================================================

#include "CPlayerNatives.h"
#include <Scripting/CLuaVM.h>
#include <Scripting/CSquirrelVM.h>
#include "../../CServer.h"
#include <CLogFile.h>

void CPlayerNatives::Register(CScriptVM * pVM)
{
	pVM->RegisterFunction("createPlayer", Create);

	pVM->RegisterFunction("print", Print); // TODO : move to antother natives class
}


int CPlayerNatives::Create(int * VM)
{
	// Just an example how the new scripting works with a lua or a squirrel vm its not needed to create a native for every language
	CResource* pResource = CServer::GetInstance()->GetResourceManager()->Get(VM);
	if(pResource)
	{
		// We do not have to split it here cause our CScriptVM class provides the nessessary push and pop/get methods
		CScriptVM* pVM = pResource->GetVM();


		CLogFile::Printf("Kekse ich mag");

		CVector3 keks;
		//pVM->PopVector(keks);

		// Create player kekse

		//pVM->PushBool(true);

		pVM->ResetStackIndex();
	}

	return 0;
}


int CPlayerNatives::Print(int * VM)
{
	// Just an example how the new scripting works with a lua or a squirrel vm its not needed to create a native for every language
	CResource* pResource = CServer::GetInstance()->GetResourceManager()->Get(VM);
	if(pResource)
	{
		// We do not have to split it here cause our CScriptVM class provides the nessessary push and pop/get methods
		CScriptVM* pVM = pResource->GetVM();
		pVM->ResetStackIndex();
		CString strPrint;
		pVM->PopString(strPrint);
		CLogFile::Printf(strPrint);

		pVM->ResetStackIndex();
	}

	return 0;
}