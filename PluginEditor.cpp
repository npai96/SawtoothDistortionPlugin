/*
 ==============================================================================
 
 This file was auto-generated!
 
 It contains the basic framework code for a JUCE plugin editor.
 
 ==============================================================================
 */

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <math.h>

//==============================================================================
SineDistortionAudioProcessorEditor::SineDistortionAudioProcessorEditor (SineDistortionAudioProcessor& p)
: AudioProcessorEditor (&p), processor (p)
{
    addAndMakeVisible(blendSlider = new Slider("Blend"));
    blendSlider->setSliderStyle(Slider::Rotary);
    blendSlider->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);
    
    addAndMakeVisible(volSlider = new Slider("Volume"));
    volSlider->setSliderStyle(Slider::Rotary);
    volSlider->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);
    
    blendAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "blend", *blendSlider);
    volAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "volume", *volSlider);
    
    blendSlider->setLookAndFeel(&paintBlend);
    volSlider->setLookAndFeel(&paintVolume);
    
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (500, 200);
}

SineDistortionAudioProcessorEditor::~SineDistortionAudioProcessorEditor()
{
}

//==============================================================================
void SineDistortionAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll(Colours::silver);
    g.setColour (Colours::red);
    Font AmpFont("Mistral", "regular", 30.0f);
    g.setFont (AmpFont);
    g.drawFittedText ("EXTRA AGGRO SAWTOOTH DISTORTION", getLocalBounds(), Justification::centredTop, 1);
    
    g.drawText("Blend", (((getWidth() / 5) * 2) - (100 / 2)), (getHeight() / 2) + 5, 100, 100, Justification::centred);
    g.drawText("Volume", (((getWidth() / 5) * 3) - (100 / 2)), (getHeight() / 2) + 5, 100, 100, Justification::centred);
}

void SineDistortionAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    blendSlider->setBounds((((getWidth() / 5) * 2) - (100 / 2)), (getHeight() / 2) - (100 / 2), 100, 100);
    volSlider->setBounds((((getWidth() / 5) * 3) - (100 / 2)), (getHeight() / 2) - (100 / 2), 100, 100);
}
