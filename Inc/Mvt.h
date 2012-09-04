
#ifndef _Mvt_h
#define _Mvt_h

class CMvt;
class CRunMvt;
class CPropValue;
class CDynamicItem;
struct PropData;

////////////////////////////////////////////////
//
// Property Helper class
//

class CMvtPropMgr
{
public:
	virtual ~CMvtPropMgr();

	// Public interface
	virtual void		AddProps(PropData* pPropData);
	virtual void		InsertProps(PropData* pPropData, UINT nInsertPropID, BOOL bAfter);
	virtual void		RemoveProp(UINT nInsertPropID);
	virtual void		RemoveProps(PropData* pPropData);
	virtual void		RefreshProp(UINT nPropID, BOOL bReInit);
	virtual CPropValue* GetPropValue(UINT nPropID);
	virtual void		SetPropValue(UINT nPropID, CPropValue* pValue);
	virtual int			GetPropCheck(UINT nPropID);
	virtual void		SetPropCheck(UINT nPropID, int nCheck);

	// Private
public:
	CMvtPropMgr(CDynamicItem* pfi);

public:
	CDynamicItem*		m_pfi;
};

////////////////////////////////////////////////
//
// Editor & Runtime class
//

#define MVT_VERSION_1	0x0001

class CMvt {

	// Protected destructor
protected:
	virtual ~CMvt() {}

///////////////////
// Public interface

public:
		// Construction / Destruction
	virtual void		Initialize() {}
    virtual void		Delete(void) { delete this; }

	// Info
	virtual HINSTANCE	GetModuleHandle() { return NULL; }
    virtual int			GetModuleName(LPSTR pBuf, int bufSize) { return 0; }

	// Operators
	virtual CMvt*		Clone() { return NULL; }
	virtual BOOL		IsEqual(CMvt* pMvt) { return FALSE; }

	// Version
	virtual int			GetVersion() { return MVT_VERSION_1; }

	// Properties
	virtual void		GetProperties(CMvtPropMgr* pMvtPropMgr, BOOL bMasterItem) {}
	virtual void		RemoveProperties(CMvtPropMgr* pMvtPropMgr) {}
	virtual CPropValue*	GetPropertyValue(CMvtPropMgr* pMvtPropMgr, UINT nPropID) { return NULL; }
	virtual void		SetPropertyValue(CMvtPropMgr* pMvtPropMgr, UINT nPropID, CPropValue* pValue) {}
	virtual int			GetPropertyCheck(CMvtPropMgr* pMvtPropMgr, UINT nPropID) { return FALSE; }
	virtual void		SetPropertyCheck(CMvtPropMgr* pMvtPropMgr, UINT nPropID, int nCheck) {}
	virtual BOOL		IsPropertyEnabled(CMvtPropMgr* pMvtPropMgr, UINT nPropID) { return TRUE; }
	virtual BOOL		EditProperty(CMvtPropMgr* pMvtPropMgr, UINT nPropID) { return FALSE; }
	virtual LPARAM		GetPropertyCreateParam(CMvtPropMgr* pMvtPropMgr, UINT nPropID) { return NULL; }
	virtual void		ReleasePropertyCreateParam(CMvtPropMgr* pMvtPropMgr, UINT nPropID, LPARAM lCreateParam) {}
	virtual BOOL		IsActionEnabled(short action) {return TRUE;}

	// Player
	virtual int			GetPlayer() { return MVCONT_COMPUTER; }
	virtual void		SetPlayer(int nPlayer) { }
	virtual BOOL		MoveAtStart()	{ return TRUE; }
	virtual int			DirAtStart()	{ return 0; }

	// Load / Save
	virtual BOOL		Load(LPBYTE pBuf, DWORD dwSize, BOOL bRuntime) { return 0; }
	virtual BOOL		Save(LPBYTE pBuf, LPDWORD pDWSize, BOOL bRuntime) { return 0; }

	// Run-time
	virtual CRunMvt*	CreateRunMvt() { return NULL; }

// End of public interface
//////////////////////////

// Private interface
public:
	// Constructor
	CMvt() {}
};
typedef	CMvt * LPMVT;


////////////////////////////////////////////////
//
// Runtime only class
//

#define RUNMVT_VERSION_1	0x0001

class CRunMvt {

	// Protected destructor
protected:
	virtual ~CRunMvt() {}

///////////////////
// Public interface

public:
	// Construction / Destruction
	virtual void		Initialize(CMvt* pMvt, LPHO hoPtr) {}
    virtual void		Delete(void) { delete this; }

	// Version
	virtual int			GetVersion() { return RUNMVT_VERSION_1; }

	virtual BOOL		Move(LPHO pHo) { return FALSE; }
	virtual void		SetPosition(LPHO pHo, int x, int y) {} 
	virtual void		SetXPosition(LPHO pHo, int x) {}
	virtual void		SetYPosition(LPHO pHo, int y) {}

	virtual void		Stop(LPHO pHo, BOOL bCurrent) {}
	virtual void		Bounce(LPHO pHo, BOOL bCurrent) {}
	virtual void		Reverse(LPHO pHo) {}
	virtual void		Start(LPHO pHo) {}
	virtual void		SetSpeed(LPHO pHo, int speed) {}
	virtual void		SetMaxSpeed(LPHO pHo, int speed) {}
	virtual void		SetDir(LPHO pHO, int dir) {}
	virtual void		SetAcc(LPHO pHo, int acc) {}
	virtual void		SetDec(LPHO pHo, int dec) {}
	virtual void		SetRotSpeed(LPHO pHo, int speed) {}
	virtual void		Set8Dirs(LPHO pHo, int dirs) {}
	virtual void		SetGravity(LPHO hoPtr, int gravity) {}
	virtual DWORD		Extension(LPHO hoPtr, int function, DWORD param) {return 0;}
	virtual DWORD		ActionEntry(LPHO hoPtr, int action, DWORD param) {return 0;}
	virtual int			GetSpeed(LPHO hoPtr) {return 0;}
	virtual int			GetAcceleration(LPHO hoPtr) {return 0;}
	virtual int			GetDeceleration(LPHO hoPtr) {return 0;}
	virtual int			GetGravity(LPHO hoPtr) {return 0;}

// End of public interface
//////////////////////////

// Private interface
public:
	// Constructor
	CRunMvt() {}
};
typedef	CRunMvt * LPRUNMVT;

#endif // _Mvt_h
