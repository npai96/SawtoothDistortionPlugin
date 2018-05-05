/*
 ==============================================================================
 
 This file was auto-generated!
 
 It contains the basic framework code for a JUCE plugin editor.
 
 ==============================================================================
 */

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include <math.h>

//==============================================================================
/**
 */
/* GUI Component */
class BlendDesign : public LookAndFeel_V4
{
public:
    BlendDesign()
    {
        setColour(Slider::rotarySliderOutlineColourId, Colours::black);
        setColour(Slider::rotarySliderFillColourId, Colours::red);
        setColour(Slider::thumbColourId, Colours::whitesmoke);
    }
};

class VolumeDesign : public LookAndFeel_V4
{
public:
    VolumeDesign()
    {
        setColour(Slider::rotarySliderOutlineColourId, Colours::black);
        setColour(Slider::rotarySliderFillColourId, Colours::red);
        setColour(Slider::thumbColourId, Colours::whitesmoke);
    }
};

/* AudioProcessor Component */
class SineDistortionAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    SineDistortionAudioProcessorEditor (SineDistortionAudioProcessor&);
    ~SineDistortionAudioProcessorEditor();
    
    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
private:
    
    /* Pointers to Sliders represent each knob in GUI.
     * ScopedPointers are pointers that are deallocated once the pointer exits scope.
     * Memory management is extremely important in audio processing as sound files
     * create audio callbacks called every 41.4kHz, audio callbacks need to be produced
     * to provide audio buffers on time (otherwise you get annoying buzzes)
     */
    ScopedPointer<Slider> blendSlider;
    ScopedPointer<Slider> volSlider;
    
    /* ValueTreeStates store parameter values, can save, store, and manage presets,
     * allow these to be shared between classes
     */
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> blendAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> volAttachment;
    
    /* GUI Components */
    BlendDesign paintBlend;
    VolumeDesign paintVolume;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SineDistortionAudioProcessor& processor;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SineDistortionAudioProcessorEditor)
};
