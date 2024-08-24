/*
  ==============================================================================

    ParamsHelper.h
    Created: 20 Aug 2024 3:54:49pm
    Author:  Linus

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

namespace ParamIDs
{
    constexpr auto nrStages = "nr.stages";
    constexpr auto spread = "spread";
    constexpr auto center = "center";
    constexpr auto feedback = "feedback";
    constexpr auto invertPolarity = "invertPolarity";
    constexpr auto depth = "depth";
    constexpr auto lfoFreq = "lfoFreq";
    constexpr auto lfoDepth = "lfoDepth";
    constexpr auto stereo = "stereo";
    constexpr auto bypass = "bypass";
    constexpr auto gain = "gain";
}

namespace ParamRange
{
    constexpr int nrStagesStart = 1;
    constexpr int nrStagesEnd = 23;
    constexpr int nrStagesInterval = 1;
    constexpr float nrStagesDefault = 1;

    constexpr float spreadStart = 0.f;
    constexpr float spreadEnd = 1.f;
    constexpr float spreadInterval = 0.1f;
    constexpr float spreadDefault = 0.01f;

    constexpr float centerStart = 20.f;
    constexpr float centerEnd = 20000.f;
    constexpr float centerInterval = 0.01f;
    constexpr float centerDefault = 1000.f;

    constexpr float feedbackStart = 0.f;
    constexpr float feedbackEnd = 1.f;
    constexpr float feedbackInterval = 0.1f;
    constexpr float feedbackDefault = 0.f;

    constexpr float invertPolarityStart = 0.f;
    constexpr float invertPolarityEnd = 0.5f;
    constexpr float invertPolarityInterval = 0.001f;

    constexpr float depthStart = 0.f;
    constexpr float depthEnd = 0.5f;
    constexpr float depthInterval = 0.001f;
    constexpr float depthDefault = 0.25f;

    constexpr float lfoFreqStart = 0.0f;
    constexpr float lfoFreqEnd = 1.50f;
    constexpr float lfoFreqInterval = 0.01f;
    constexpr float lfoFreqDefault = 0.01f;

    constexpr float lfoDepthStart = 0.f;
    constexpr float lfoDepthEnd = 1.f;
    constexpr float lfoDepthInterval = 0.01f;
    constexpr float lfoDepthDefault = 0.5f;

    constexpr float stereoStart = 0.f;
    constexpr float stereoEnd = 1.f;
    constexpr float stereoInterval = 0.01f;
    constexpr float stereoDefault = 0.f;

    constexpr float gainStart = -40.0f;
    constexpr float gainEnd = 40.0f;
    constexpr float gainInterval = 0.1f;
    constexpr float gainDefault = 0.1f;
}

class ParamsHelper
{
public:
    juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
};