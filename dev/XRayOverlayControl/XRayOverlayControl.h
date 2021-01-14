// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#pragma once

#include "pch.h"
#include "common.h"

#include "XRayOverlayControl.g.h"
#include "XRayOverlayControl.properties.h"

#pragma warning(push)
#pragma warning(disable: 6101)  // Returning uninitialized memory '<value>'.  A successful path through the function does not set the named _Out_ parameter.
#include "Microsoft.UI.Composition.Effects_impl.h"
#pragma warning(pop)

class XRayOverlayControl :
    public ReferenceTracker<XRayOverlayControl, winrt::implementation::XRayOverlayControlT>,
    public XRayOverlayControlProperties
{

public:
    XRayOverlayControl();
    ~XRayOverlayControl() {}

    void OnPropertyChanged(const winrt::DependencyPropertyChangedEventArgs& args);

private:
    void UpdateBrush();

    winrt::CompositionEffectFactory _effectFactory{ nullptr };
    winrt::Color _replacementColor{};
};
