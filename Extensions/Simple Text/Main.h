
// Object identifier "SAMT"

#pragma message ("************************ WARNING ****************************")
#pragma message ("***** Do not forget to change the IDENTIFIER in Main.h! *****")
#pragma message ("*************************************************************")

#define IDENTIFIER	MAKEID(S,A,M,T)		// REQUIRED: you MUST replace the letters in the MAKEID macro by others
										// and then remove the #pragma message above. If you do not do this, MMF2
										// could confuse your object with another in the event editor.

// ------------------------------
// DEFINITION OF CONDITIONS CODES
// ------------------------------
#define	CND_CONDITION				0
#define	CND_LAST					1

// ---------------------------
// DEFINITION OF ACTIONS CODES
// ---------------------------
#define	ACT_SETTEXT					0
#define	ACT_LAST					1

// -------------------------------
// DEFINITION OF EXPRESSIONS CODES
// -------------------------------
#define	EXP_GETTEXT					0
#define	EXP_LAST                    1

// ---------------------
// OBJECT DATA STRUCTURE 
// ---------------------
// Used at edit time and saved in the MFA/CCN/EXE files

typedef struct tagEDATA_V1
{
	// Header - required
	extHeader		eHeader;

	// Object's data
	LONG			nWidth;			// width
	LONG			nHeight;		// height
	COLORREF		textColor;		// text color
	DWORD			dwAlignFlags;	// alignment flags
	LOGFONT			textFont;		// text font
	char			sText[1];		// text (dynamic size)

} EDITDATA;
typedef EDITDATA *			LPEDATA;

// Object versions
#define	KCX_CURRENT_VERSION			1

// --------------------------------
// RUNNING OBJECT DATA STRUCTURE
// --------------------------------
// Used at runtime. Initialize it in the CreateRunObject function.
// Free any allocated memory or object in the DestroyRunObject function.
//
// Note: if you store C++ objects in this structure and do not store 
// them as pointers, you must call yourself their constructor in the
// CreateRunObject function and their destructor in the DestroyRunObject
// function. As the RUNDATA structure is a simple C structure and not a C++ object.

typedef struct tagRDATA
{
	// Main header - required
	headerObject	rHo;			// Main header - required

	// Optional headers - depend on the OEFLAGS value, see documentation and examples for more info
	rCom			rc;				// Common structure for movements & animations
	rMvt			rm;				// Movements
	rSpr			rs;				// Sprite (displayable objects)
	rVal			rv;				// Alterable values

	// Object's runtime data
	COLORREF		textColor;		// text color
	DWORD			dwAlignFlags;	// alignment flags
	HFONT			hFont;		// text font
	LPSTR			pText;			// Text

} RUNDATA;
typedef	RUNDATA	*			LPRDATA;

// Size when editing the object under level editor
// -----------------------------------------------
#define	MAX_EDITSIZE			sizeof(EDITDATA)

// Default flags
// -------------
#define	OEFLAGS	(OEFLAG_SPRITES|OEFLAG_BACKSAVE|/*OEFLAG_INTERNALBACKSAVE|*/OEFLAG_MOVEMENTS|OEFLAG_VALUES|OEFLAG_TEXT)
#define	OEPREFS	(OEPREFS_BACKSAVE|OEPREFS_KILL|OEPREFS_BACKEFFECTS|OEPREFS_SCROLLINGINDEPENDANT|OEPREFS_INKEFFECTS)


// If to handle message, specify the priority of the handling procedure
// 0= low, 255= very high. You should use 100 as normal.                                                
// --------------------------------------------------------------------
#define	WINDOWPROC_PRIORITY		100
