// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#include "pch.h"
#include "common.h"
#include "XRayOverlayControl.h"
#include "RuntimeProfiler.h"
#include "ResourceAccessor.h"

struct XamlCompBrush : winrt::Windows::UI::Xaml::Media::XamlCompositionBrushBaseT<XamlCompBrush>
{
    void SetCompositionBrush(winrt::CompositionBrush const& brush)
    {
        CompositionBrush(brush);
    }
};

XRayOverlayControl::XRayOverlayControl()
{
    SizeChanged([this](auto&&...) {
        UpdateBrush();
        });
}

void  XRayOverlayControl::OnPropertyChanged(const winrt::DependencyPropertyChangedEventArgs& args)
{
    winrt::IDependencyProperty property = args.Property();
    
    UpdateBrush();
}


void XRayOverlayControl::UpdateBrush()
{
    if (auto targetElement = TargetElement())
    {
        auto const newColor = ReplacementColor();
        if (_replacementColor != newColor)
        {
            _replacementColor = newColor;
            _effectFactory = nullptr;
        }

        auto compositor = winrt::Window::Current().Compositor();

        if (!_effectFactory)
        {
            auto colorMatrixEffect = winrt::make_self<Microsoft::UI::Composition::Effects::ColorMatrixEffect>();
            colorMatrixEffect->Name(L"ColorMatrix");
            //colorMatrixEffect->Source([]() -> winrt::IGraphicsEffectSource {
            //    auto transform2DEffect = winrt::make_self<Microsoft::UI::Composition::Effects::Transform2DEffect>();
            //    transform2DEffect->Source(winrt::CompositionEffectSourceParameter{ L"source" });
            //    return *transform2DEffect;
            //    }());
            colorMatrixEffect->Source(winrt::CompositionEffectSourceParameter{ L"source" });
            winrt::Matrix5x4 colorMatrix = {};
            colorMatrix.M51 = (float)((_replacementColor.R / 255.0));
            colorMatrix.M52 = (float)((_replacementColor.G / 255.0));
            colorMatrix.M53 = (float)((_replacementColor.B / 255.0));
            colorMatrix.M44 = 1;
            colorMatrixEffect->ColorMatrix(colorMatrix);

            _effectFactory = compositor.CreateEffectFactory(*colorMatrixEffect);
        }

        auto transform = TransformToVisual(targetElement);
        auto const offset = transform.TransformPoint(winrt::Point{ 0, 0 });

        auto surfaceBrush = compositor.CreateSurfaceBrush();
        surfaceBrush.Stretch(winrt::CompositionStretch::None);
        auto surface = compositor.CreateVisualSurface();
        surface.SourceVisual(winrt::ElementCompositionPreview::GetElementVisual(targetElement));
        surface.SourceOffset({ offset.X, offset.Y });
        surface.SourceSize({ (float)ActualWidth(), (float)ActualHeight() });
        surfaceBrush.Surface(surface);
        surfaceBrush.Stretch(winrt::CompositionStretch::None);
        auto compBrush = _effectFactory.CreateBrush();
        compBrush.SetSourceParameter(L"source", surfaceBrush);

        auto visual = compositor.CreateSpriteVisual();
        visual.Size({ (float)ActualWidth(), (float)ActualHeight() });
        visual.Brush(compBrush);

        winrt::ElementCompositionPreview::SetElementChildVisual(*this, visual);
    }

}
