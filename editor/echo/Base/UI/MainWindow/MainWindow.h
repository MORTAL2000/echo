#pragma once

#include <QProcess>
#include "ui_MainWindow.h"
#include <engine/core/util/StringUtil.h>

namespace Studio
{
	class ResPanel;
	class NodeTreePanel;
	class TimelinePanel;
	class DebuggerPanel;
	class BottomPanel;
	class PlayGameToolBar;
	class MainWindow : public QMainWindow, public Ui_MainWindow
	{
		Q_OBJECT

	public:
		MainWindow(QMainWindow* parent=0);
		~MainWindow();

		// instance
		static MainWindow* instance();

		// 打开项目时调用
		void onOpenProject();

		// 打开文件
		void OpenProject(const char* projectName);

		// open lua file for edit
		void openLuaScript(const Echo::String& fileName);

	protected:
		void closeEvent(QCloseEvent *event);

	public slots:
		// scene operate
		void onNewScene();
		void onSaveScene();
		void onSaveAsScene();

		// project operate
		void onNewAnotherProject();
		void onOpenAnotherProject();
		void onSaveProject();
		void onSaveasProject();
		void onOpenRencentProject();

		// game mode
		void onPlayGame();

		// receive msg from game
		void onReadMsgFromGame();

		// game process exit
		void onGameProcessFinished(int id, QProcess::ExitStatus status);

	protected:
		// open another project
		void openAnotherProject(const Echo::String& fullPathName);

		// update rencent project display
		void updateRencentProjectsDisplay();

	protected:
		ResPanel*		m_resPanel;
		NodeTreePanel*	m_scenePanel;
		BottomPanel*	m_bottomPanel;

		QProcess		m_gameProcess;
		PlayGameToolBar*m_playGameToolBar;
	};
}