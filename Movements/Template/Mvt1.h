
#ifndef Mvt1_h
#define Mvt1_h

#include "MvtExt.h"

////////////////////////////////////////////////
//
// Editor & Runtime class
//
class CMvt1 : public CMvt {

///////////////////
// Public interface

	// Protected destructor
protected:
	virtual ~CMvt1();

public:
		// Construction / Destruction
	virtual void		Initialize();
    //virtual void		Delete(void);

	// Info
	virtual HINSTANCE	GetModuleHandle();
    //virtual int			GetModuleName(LPSTR pBuf, int bufSize) { return 0; }

	// Operators
	virtual CMvt*		Clone();
	virtual BOOL		IsEqual(CMvt* pMvt);

	// Properties
	virtual void		GetProperties(CMvtPropMgr* pMvtPropMgr, BOOL bMasterItem);
	virtual void		RemoveProperties(CMvtPropMgr* pMvtPropMgr);
	virtual CPropValue*	GetPropertyValue(CMvtPropMgr* pMvtPropMgr, UINT nPropID);
	virtual void		SetPropertyValue(CMvtPropMgr* pMvtPropMgr, UINT nPropID, CPropValue* pValue);
	virtual int			GetPropertyCheck(CMvtPropMgr* pMvtPropMgr, UINT nPropID);
	virtual void		SetPropertyCheck(CMvtPropMgr* pMvtPropMgr, UINT nPropID, int nCheck);
	virtual BOOL		IsPropertyEnabled(CMvtPropMgr* pMvtPropMgr, UINT nPropID);
	virtual BOOL		EditProperty(CMvtPropMgr* pMvtPropMgr, UINT nPropID);
	virtual LPARAM		GetPropertyCreateParam(CMvtPropMgr* pMvtPropMgr, UINT nPropID);
	virtual void		ReleasePropertyCreateParam(CMvtPropMgr* pMvtPropMgr, UINT nPropID, LPARAM lCreateParam);
	virtual BOOL		IsActionEnabled(short action);

	// Player
	virtual int			GetPlayer();
	virtual void		SetPlayer(int nPlayer);
	virtual BOOL		MoveAtStart();
	virtual int			DirAtStart();

	// Load / Save
	virtual BOOL		Load(LPBYTE pBuf, DWORD dwSize, BOOL bRuntime);
	virtual BOOL		Save(LPBYTE pBuf, LPDWORD pDWSize, BOOL bRuntime);

	// Run-time
	virtual CRunMvt*	CreateRunMvt();

	// Data
public:
	DWORD		m_dwSpeed;
	DWORD		m_dwFlags;
	DWORD		m_dwNOfSegments;
	DWORD		m_dwInitialDir;

// End of public interface
//////////////////////////

// Private interface
public:
	// Constructor
	CMvt1();

	static	PropData MvtProps[];
};


////////////////////////////////////////////////
//
// Runtime only class
//
class CRunMvt1 : public CRunMvt {

	// Protected destructor
protected:
	virtual ~CRunMvt1();

///////////////////
// Public interface

public:
	// Construction / Destruction
	virtual void		Initialize(CMvt* pMvt, LPHO hoPtr);
    //virtual void		Delete(void) { delete this; }

	virtual BOOL		Move(LPHO pHo);
	virtual void		SetPosition(LPHO pHo, int x, int y);
	virtual void		SetXPosition(LPHO pHo, int x);
	virtual void		SetYPosition(LPHO pHo, int y);

	virtual void		Stop(LPHO pHo, BOOL bCurrent);
	virtual void		Bounce(LPHO pHo, BOOL bCurrent);
	virtual void		Reverse(LPHO pHo);
	virtual void		Start(LPHO pHo);
	virtual void		SetSpeed(LPHO pHo, int speed);
	virtual void		SetMaxSpeed(LPHO pHo, int speed);
	virtual void		SetDir(LPHO pHo, int dir);
	virtual void		SetAcc(LPHO pHo, int acc);
	virtual void		SetDec(LPHO pHo, int dec);
	virtual void		SetRotSpeed(LPHO pHo, int speed);
	virtual void		Set8Dirs(LPHO pHo, int dirs);
	virtual void		SetGravity(LPHO pHo, int gravity);
	virtual DWORD		Extension(LPHO pHo, int function, DWORD param);
	virtual DWORD		ActionEntry(LPHO pHo, int action, DWORD param);
	virtual int			GetSpeed(LPHO hoPtr);
	virtual int			GetAcceleration(LPHO hoPtr);
	virtual int			GetDeceleration(LPHO hoPtr);
	virtual int			GetGravity(LPHO hoPtr);

// End of public interface
//////////////////////////

// Private interface
public:
	// Constructor
	CRunMvt1();

// Private data
public:
	CMvt1*	m_pMvt;
	int m_segmentCount;
	int m_dir;


};

enum
{
	MFLAG1_MOVEATSTART=1
};

#endif // Mvt1_h
