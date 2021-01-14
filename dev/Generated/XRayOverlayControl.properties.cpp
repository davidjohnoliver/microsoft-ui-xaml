// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

// DO NOT EDIT! This file was generated by CustomTasks.DependencyPropertyCodeGen
#include "pch.h"
#include "common.h"
#include "XRayOverlayControl.h"

namespace winrt::Microsoft::UI::Xaml::Controls::Primitives
{
    CppWinRTActivatableClassWithDPFactory(XRayOverlayControl)
}

#include "XRayOverlayControl.g.cpp"

GlobalDependencyProperty XRayOverlayControlProperties::s_ReplacementColorProperty{ nullptr };
GlobalDependencyProperty XRayOverlayControlProperties::s_TargetElementProperty{ nullptr };

XRayOverlayControlProperties::XRayOverlayControlProperties()
{
    EnsureProperties();
}

void XRayOverlayControlProperties::EnsureProperties()
{
    if (!s_ReplacementColorProperty)
    {
        s_ReplacementColorProperty =
            InitializeDependencyProperty(
                L"ReplacementColor",
                winrt::name_of<winrt::Color>(),
                winrt::name_of<winrt::XRayOverlayControl>(),
                false /* isAttached */,
                ValueHelper<winrt::Color>::BoxedDefaultValue(),
                winrt::PropertyChangedCallback(&OnReplacementColorPropertyChanged));
    }
    if (!s_TargetElementProperty)
    {
        s_TargetElementProperty =
            InitializeDependencyProperty(
                L"TargetElement",
                winrt::name_of<winrt::UIElement>(),
                winrt::name_of<winrt::XRayOverlayControl>(),
                false /* isAttached */,
                ValueHelper<winrt::UIElement>::BoxedDefaultValue(),
                winrt::PropertyChangedCallback(&OnTargetElementPropertyChanged));
    }
}

void XRayOverlayControlProperties::ClearProperties()
{
    s_ReplacementColorProperty = nullptr;
    s_TargetElementProperty = nullptr;
}

void XRayOverlayControlProperties::OnReplacementColorPropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::XRayOverlayControl>();
    winrt::get_self<XRayOverlayControl>(owner)->OnPropertyChanged(args);
}

void XRayOverlayControlProperties::OnTargetElementPropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::XRayOverlayControl>();
    winrt::get_self<XRayOverlayControl>(owner)->OnPropertyChanged(args);
}

void XRayOverlayControlProperties::ReplacementColor(winrt::Color const& value)
{
    [[gsl::suppress(con)]]
    {
    static_cast<XRayOverlayControl*>(this)->SetValue(s_ReplacementColorProperty, ValueHelper<winrt::Color>::BoxValueIfNecessary(value));
    }
}

winrt::Color XRayOverlayControlProperties::ReplacementColor()
{
    return ValueHelper<winrt::Color>::CastOrUnbox(static_cast<XRayOverlayControl*>(this)->GetValue(s_ReplacementColorProperty));
}

void XRayOverlayControlProperties::TargetElement(winrt::UIElement const& value)
{
    [[gsl::suppress(con)]]
    {
    static_cast<XRayOverlayControl*>(this)->SetValue(s_TargetElementProperty, ValueHelper<winrt::UIElement>::BoxValueIfNecessary(value));
    }
}

winrt::UIElement XRayOverlayControlProperties::TargetElement()
{
    return ValueHelper<winrt::UIElement>::CastOrUnbox(static_cast<XRayOverlayControl*>(this)->GetValue(s_TargetElementProperty));
}
