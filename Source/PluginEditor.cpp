/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
VolumeControlAudioProcessorEditor::VolumeControlAudioProcessorEditor (VolumeControlAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{   
    gainSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    addAndMakeVisible(gainSlider);

    gainSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "VOLUME", gainSlider);

    setSize (400, 300);
}

VolumeControlAudioProcessorEditor::~VolumeControlAudioProcessorEditor()
{
}

//==============================================================================
void VolumeControlAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

}

void VolumeControlAudioProcessorEditor::resized()
{
    gainSlider.setBounds(getWidth() / 2 - 200, getHeight() / 2 -100, 200, 200);

}
