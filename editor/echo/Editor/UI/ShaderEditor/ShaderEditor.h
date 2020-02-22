#pragma once

#include <QHBoxLayout>
#include <QDockWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <nodeeditor/NodeDataModel>
#include <engine/core/util/StringUtil.h>
#include <engine/core/render/base/ShaderProgram.h>
#include "Scene/ShaderScene.h"
#include "Scene/ShaderView.h"
#include "ui_ShaderEditor.h"

namespace Studio
{
	class ShaderEditor : public QDockWidget , public Ui_ShaderEditorPanel
	{
		Q_OBJECT

	public:
		ShaderEditor(QWidget* parent = 0);
		~ShaderEditor();
        
        void visitorAllNodes(QtNodes::NodeDataModel* dataModel);
        
        // compile
        void compile();
        
    public slots:
        // open
        void open(const Echo::String& resPath);
        
        // save
        void save();

    protected:
        // adjust view
        void adjustViewRect();

	private:
        bool                                m_isLoading = false;
        Echo::ShaderProgramPtr              m_shaderProgram;
		DataFlowProgramming::ShaderScene*	m_graphicsScene = nullptr;
		DataFlowProgramming::ShaderView*	m_graphicsView = nullptr;
        std::string                         m_fsMacros;
        std::string                         m_fsUniforms;
        std::string                         m_fsTextureUniforms;
        std::string                         m_fsCode;
	};
}
