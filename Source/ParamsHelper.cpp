/*
  ==============================================================================

    ParamsHelper.h
    Created: 20 Aug 2024 3:54:49pm
    Author:  Linus

  ==============================================================================
*/


#include "ParamsHelper.h"

juce::AudioProcessorValueTreeState::ParameterLayout ParamsHelper::createParameterLayout()
{
    using namespace juce;

    std::vector<std::unique_ptr<RangedAudioParameter>> params;

    params.push_back(
        std::make_unique<AudioParameterInt>(ParamIDs::nrStages,
            "Nr Of Stages",
            ParamRange::nrStagesStart,
            ParamRange::nrStagesEnd,
            ParamRange::nrStagesDefault
        ));

    params.push_back(
        std::make_unique<AudioParameterFloat>(ParamIDs::spread,
            "Spread",
            NormalisableRange<float>(ParamRange::spreadStart, ParamRange::spreadEnd, ParamRange::spreadInterval),
            ParamRange::spreadDefault,
            String(),
            AudioProcessorParameter::genericParameter,
            [](float value, float)
            {
                return String(value * 100.0f, 1) + " %";
            }
    ));

    params.push_back(
        std::make_unique<juce::AudioParameterFloat>(ParamIDs::center,
            "Center",
            juce::NormalisableRange<float>(ParamRange::centerStart, ParamRange::centerEnd, ParamRange::centerInterval), // , 0.5f), // skewfactor
            ParamRange::centerDefault,
            "Hz",
            juce::AudioProcessorParameter::genericParameter,
            [](float value, float)
            {
                return juce::String(value, 1) + " Hz";
            }
    ));

    params.push_back(
        std::make_unique<AudioParameterFloat>(ParamIDs::feedback,
            "Feedback",
            NormalisableRange<float>(ParamRange::feedbackStart, ParamRange::feedbackEnd),
            ParamRange::feedbackDefault,
            String(),
            AudioProcessorParameter::genericParameter,
            [](float value, float)
            {
                return String(value * 100.0f, 1) + " %";
            }
    ));

    params.push_back(std::make_unique<AudioParameterBool>(ParamIDs::invertPolarity, "Invert Polarity", false));

    params.push_back(
        std::make_unique<AudioParameterFloat>(ParamIDs::depth,
            "Depth",
            NormalisableRange<float>(ParamRange::depthStart, ParamRange::depthEnd, ParamRange::depthInterval),
            ParamRange::depthDefault,
            String(),
            AudioProcessorParameter::genericParameter,
            [](float value, float)
            {
                return String(value * 200.0f, 1) + " %";
            }
    ));

    params.push_back(
        std::make_unique<AudioParameterFloat>(ParamIDs::lfoFreq,
            "LFO Frequency",
            NormalisableRange<float>(ParamRange::lfoFreqStart, ParamRange::lfoFreqEnd, ParamRange::lfoFreqInterval),
            ParamRange::lfoFreqDefault,
            String(),
            AudioProcessorParameter::genericParameter,
            [](float value, float)
            {
                return String(value, 0.01) + " Hz";
            }
    ));

    params.push_back(
        std::make_unique<AudioParameterFloat>(ParamIDs::lfoDepth,
            "LFO Depth",
            NormalisableRange<float>(ParamRange::lfoDepthStart, ParamRange::lfoDepthEnd, ParamRange::lfoDepthInterval),
            ParamRange::lfoDepthDefault
        ));

    params.push_back(
        std::make_unique<AudioParameterFloat>(ParamIDs::stereo,
            "Stereo",
            NormalisableRange<float>(ParamRange::stereoStart, ParamRange::stereoEnd, ParamRange::stereoInterval),
            ParamRange::stereoDefault,
            String(),
            AudioProcessorParameter::genericParameter,
            [](float value, float)
            {
                return String(value * 100, 1) + " %";
            }
    ));


    params.push_back(std::make_unique<AudioParameterFloat>(ParamIDs::gain, 
            "Gain",
            NormalisableRange<float>(
            ParamRange::gainStart,
            ParamRange::gainEnd,
            ParamRange::gainInterval), 
            ParamRange::gainDefault,
            String(),
            AudioProcessorParameter::genericParameter,
            [](float value, float)
            {
                return String(value, 1) + " dB ";
            }
    ));

    params.push_back(std::make_unique<AudioParameterBool>(ParamIDs::bypass, "Bypass", false));

    return { params.begin(), params.end() };
}