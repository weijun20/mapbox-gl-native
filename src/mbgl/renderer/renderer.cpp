#include <mbgl/renderer/renderer.hpp>
#include <mbgl/renderer/renderer_impl.hpp>
#include <mbgl/renderer/update_parameters.hpp>

namespace mbgl {

Renderer::Renderer(Backend& backend,
                   float pixelRatio_,
                   FileSource& fileSource_,
                   Scheduler& scheduler_,
                   MapMode mode_,
                   GLContextMode contextMode_,
                   const optional<std::string> programCacheDir_)
        : impl(std::make_unique<Impl>(backend, pixelRatio_, fileSource_, scheduler_, mode_,
                                      contextMode_, std::move(programCacheDir_))) {
}

Renderer::~Renderer() = default;

void Renderer::setObserver(RendererObserver* observer) {
    impl->setObserver(observer);
}

void Renderer::render(View& view, const UpdateParameters& updateParameters) {
    impl->render(view, updateParameters);
}

std::vector<Feature> Renderer::queryRenderedFeatures(const RenderedQueryParameters& params) const {
    return impl->queryRenderedFeatures(params);
}

std::vector<Feature> Renderer::querySourceFeatures(const SourceQueryParameters& params) const {
    return impl->querySourceFeatures(params);
}

void Renderer::dumpDebugLogs() {
    impl->dumDebugLogs();
}

void Renderer::onLowMemory() {
    impl->onLowMemory();
}

} // namespace mbgl
