
// HelloJPGDlg.h : header file
//

#pragma once
extern void startHelloJPG(void* phy_fb, int width, int height, int color_bytes);
extern void sendTouch2HelloJPG(int x, int y, bool is_down);
extern void* getUiOfHelloJPG(int* width, int* height, bool force_update = false);

typedef struct tagMYBITMAPINFO {
	BITMAPINFOHEADER    bmiHeader;
	DWORD				biRedMask;
	DWORD				biGreenMask;
	DWORD				biBlueMask;
} MYBITMAPINFO;

// CHelloJPGDlg dialog
class CHelloJPGDlg : public CDialogEx
{
// Construction
public:
	CHelloJPGDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HelloJPG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	DECLARE_MESSAGE_MAP()

private:
	void updateUI(CDC* pDC);
	CPoint pointMFC2GuiLite(CPoint point);
	static UINT ThreadHelloJPG(LPVOID pParam);
	static UINT ThreadRefreshUI(LPVOID pParam);
	static CHelloJPGDlg* m_the_dialog;
	CRect m_block_rect;
	int m_ui_width;
	int m_ui_height;
	int m_color_bytes;
	CBitmap		m_blockBmp;
	MYBITMAPINFO m_ui_bm_info;
	CDC			m_memDC;
};
