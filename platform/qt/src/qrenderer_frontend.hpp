#pragma once

#include <mbgl/renderer/renderer_frontend.hpp>

#include <QObject>

namespace mbgl {
    class View;
} // namespace mbgl

class QRendererFrontend : public QObject, public mbgl::RendererFrontend
{
    Q_OBJECT

public:
    explicit QRendererFrontend(std::unique_ptr<mbgl::Renderer>, mbgl::View&);
    ~QRendererFrontend() override;
    
    void reset() override;
    void setObserver(mbgl::RendererObserver&) override;

    void update(std::shared_ptr<mbgl::UpdateParameters>) override;
    
    std::vector<mbgl::Feature> queryRenderedFeatures(mbgl::ScreenLineString, mbgl::RenderedQueryOptions) const override;
    std::vector<mbgl::Feature> querySourceFeatures(std::string sourceID, mbgl::SourceQueryOptions) const override;
    
    void onLowMemory(); //slot?

public slots:
    void render();

signals:
    void updated();
    
private:
    std::unique_ptr<mbgl::Renderer> renderer;
    mbgl::View& view;
    std::shared_ptr<mbgl::UpdateParameters> updateParameters;
};
