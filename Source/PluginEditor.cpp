#include <juce_gui_extra/juce_gui_extra.h>
#include "PluginProcessor.h"
#include "PluginEditor.h"

MantraAudioProcessorEditor::MantraAudioProcessorEditor(MantraAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
    // Input stage
    inputGainSlider = std::make_unique<juce::Slider>(juce::Slider::RotaryVerticalDrag, juce::Slider::TextBoxBelow);
    addAndMakeVisible(*inputGainSlider);
    inputGainAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.apvts, "inputGain", *inputGainSlider);

    inputGainLabel = std::make_unique<juce::Label>("", "Input Gain");
    addAndMakeVisible(*inputGainLabel);
    inputGainLabel->attachToComponent(inputGainSlider.get(), false);

    // Drive
    driveSlider = std::make_unique<juce::Slider>(juce::Slider::RotaryVerticalDrag, juce::Slider::TextBoxBelow);
    addAndMakeVisible(*driveSlider);
    driveAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.apvts, "drive", *driveSlider);

    driveLabel = std::make_unique<juce::Label>("", "Drive");
    addAndMakeVisible(*driveLabel);
    driveLabel->attachToComponent(driveSlider.get(), false);

    // Tone
    toneSlider = std::make_unique<juce::Slider>(juce::Slider::RotaryVerticalDrag, juce::Slider::TextBoxBelow);
    addAndMakeVisible(*toneSlider);
    toneAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.apvts, "tone", *toneSlider);

    toneLabel = std::make_unique<juce::Label>("", "Tone");
    addAndMakeVisible(*toneLabel);
    toneLabel->attachToComponent(toneSlider.get(), false);

    // Bass
    bassSlider = std::make_unique<juce::Slider>(juce::Slider::RotaryVerticalDrag, juce::Slider::TextBoxBelow);
    addAndMakeVisible(*bassSlider);
    bassAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.apvts, "bass", *bassSlider);

    bassLabel = std::make_unique<juce::Label>("", "Bass");
    addAndMakeVisible(*bassLabel);
    bassLabel->attachToComponent(bassSlider.get(), false);

    // Mid
    midSlider = std::make_unique<juce::Slider>(juce::Slider::RotaryVerticalDrag, juce::Slider::TextBoxBelow);
    addAndMakeVisible(*midSlider);
    midAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.apvts, "mid", *midSlider);

    midLabel = std::make_unique<juce::Label>("", "Mid");
    addAndMakeVisible(*midLabel);
    midLabel->attachToComponent(midSlider.get(), false);

    // Treble
    trebleSlider = std::make_unique<juce::Slider>(juce::Slider::RotaryVerticalDrag, juce::Slider::TextBoxBelow);
    addAndMakeVisible(*trebleSlider);
    trebleAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.apvts, "treble", *trebleSlider);

    trebleLabel = std::make_unique<juce::Label>("", "Treble");
    addAndMakeVisible(*trebleLabel);
    trebleLabel->attachToComponent(trebleSlider.get(), false);

    // Presence
    presenceSlider = std::make_unique<juce::Slider>(juce::Slider::RotaryVerticalDrag, juce::Slider::TextBoxBelow);
    addAndMakeVisible(*presenceSlider);
    presenceAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.apvts, "presence", *presenceSlider);

    presenceLabel = std::make_unique<juce::Label>("", "Presence");
    addAndMakeVisible(*presenceLabel);
    presenceLabel->attachToComponent(presenceSlider.get(), false);

    // Compressor Threshold
    compThresholdSlider = std::make_unique<juce::Slider>(juce::Slider::RotaryVerticalDrag, juce::Slider::TextBoxBelow);
    addAndMakeVisible(*compThresholdSlider);
    compThresholdAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.apvts, "compThreshold", *compThresholdSlider);

    compThresholdLabel = std::make_unique<juce::Label>("", "Comp Thresh");
    addAndMakeVisible(*compThresholdLabel);
    compThresholdLabel->attachToComponent(compThresholdSlider.get(), false);

    // Compressor Ratio
    compRatioSlider = std::make_unique<juce::Slider>(juce::Slider::RotaryVerticalDrag, juce::Slider::TextBoxBelow);
    addAndMakeVisible(*compRatioSlider);
    compRatioAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.apvts, "compRatio", *compRatioSlider);

    compRatioLabel = std::make_unique<juce::Label>("", "Comp Ratio");
    addAndMakeVisible(*compRatioLabel);
    compRatioLabel->attachToComponent(compRatioSlider.get(), false);

    // Output Gain
    outputGainSlider = std::make_unique<juce::Slider>(juce::Slider::RotaryVerticalDrag, juce::Slider::TextBoxBelow);
    addAndMakeVisible(*outputGainSlider);
    outputGainAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.apvts, "outputGain", *outputGainSlider);

    outputGainLabel = std::make_unique<juce::Label>("", "Output Gain");
    addAndMakeVisible(*outputGainLabel);
    outputGainLabel->attachToComponent(outputGainSlider.get(), false);

    // Reverb Room Size
    reverbRoomSlider = std::make_unique<juce::Slider>(juce::Slider::RotaryVerticalDrag, juce::Slider::TextBoxBelow);
    addAndMakeVisible(*reverbRoomSlider);
    reverbRoomAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.apvts, "reverbRoomSize", *reverbRoomSlider);

    reverbRoomLabel = std::make_unique<juce::Label>("", "Room Size");
    addAndMakeVisible(*reverbRoomLabel);
    reverbRoomLabel->attachToComponent(reverbRoomSlider.get(), false);

    // Reverb Width
    reverbWidthSlider = std::make_unique<juce::Slider>(juce::Slider::RotaryVerticalDrag, juce::Slider::TextBoxBelow);
    addAndMakeVisible(*reverbWidthSlider);
    reverbWidthAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.apvts, "reverbWidth", *reverbWidthSlider);

    reverbWidthLabel = std::make_unique<juce::Label>("", "Width");
    addAndMakeVisible(*reverbWidthLabel);
    reverbWidthLabel->attachToComponent(reverbWidthSlider.get(), false);

    // Reverb Wet
    reverbWetSlider = std::make_unique<juce::Slider>(juce::Slider::RotaryVerticalDrag, juce::Slider::TextBoxBelow);
    addAndMakeVisible(*reverbWetSlider);
    reverbWetAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.apvts, "reverbWet", *reverbWetSlider);

    reverbWetLabel = std::make_unique<juce::Label>("", "Wet");
    addAndMakeVisible(*reverbWetLabel);
    reverbWetLabel->attachToComponent(reverbWetSlider.get(), false);

    // Reverb Dry
    reverbDrySlider = std::make_unique<juce::Slider>(juce::Slider::RotaryVerticalDrag, juce::Slider::TextBoxBelow);
    addAndMakeVisible(*reverbDrySlider);
    reverbDryAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.apvts, "reverbDry", *reverbDrySlider);

    reverbDryLabel = std::make_unique<juce::Label>("", "Dry");
    addAndMakeVisible(*reverbDryLabel);
    reverbDryLabel->attachToComponent(reverbDrySlider.get(), false);

    // Cabinet IR loader
    loadIRButton = std::make_unique<juce::TextButton>("Load IR...");
    addAndMakeVisible(*loadIRButton);
    loadIRButton->onClick = [this]
    {
        irFileChooser = std::make_unique<juce::FileChooser>(
            "Select an impulse response", juce::File(), "*.wav;*.aif;*.aiff;*.flac");
        irFileChooser->launchAsync(
            juce::FileBrowserComponent::openMode | juce::FileBrowserComponent::canSelectFiles,
            [this](const juce::FileChooser& fc)
            {
                auto file = fc.getResult();
                if (file.existsAsFile())
                {
                    audioProcessor.loadImpulseResponse(file);
                    irNameLabel->setText(audioProcessor.getIRName(), juce::dontSendNotification);
                }
            });
    };

    clearIRButton = std::make_unique<juce::TextButton>("Clear");
    addAndMakeVisible(*clearIRButton);
    clearIRButton->onClick = [this]
    {
        audioProcessor.clearImpulseResponse();
        irNameLabel->setText("No IR loaded", juce::dontSendNotification);
    };

    irNameLabel = std::make_unique<juce::Label>(
        "", audioProcessor.getIRName().isNotEmpty() ? audioProcessor.getIRName() : "No IR loaded");
    addAndMakeVisible(*irNameLabel);

    // Must come after the sliders exist — setSize() synchronously calls resized()
    setSize(1080, 520);
}

MantraAudioProcessorEditor::~MantraAudioProcessorEditor()
{
}

void MantraAudioProcessorEditor::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colour::fromRGB(30, 30, 35));

    g.setColour(juce::Colours::white);
    g.setFont(24.0f);
    g.drawText("MANTRA", getLocalBounds().removeFromTop(40), juce::Justification::centred, true);

    // Section labels
    g.setFont(14.0f);
    g.setColour(juce::Colour::fromRGB(150, 150, 150));

    g.drawText("INPUT", juce::Rectangle<int>(20, 50, 175, 20), juce::Justification::centred);
    g.drawText("TONE", juce::Rectangle<int>(210, 50, 80, 20), juce::Justification::centred);
    g.drawText("EQ", juce::Rectangle<int>(400, 50, 365, 20), juce::Justification::centred);
    g.drawText("DYNAMICS", juce::Rectangle<int>(780, 50, 175, 20), juce::Justification::centred);
    g.drawText("OUTPUT", juce::Rectangle<int>(970, 50, 80, 20), juce::Justification::centred);
    g.drawText("REVERB", juce::Rectangle<int>(20, 290, 365, 20), juce::Justification::centred);
    g.drawText("CABINET IR", juce::Rectangle<int>(450, 290, 300, 20), juce::Justification::centred);
}

void MantraAudioProcessorEditor::resized()
{
    auto bounds = getLocalBounds().reduced(10);
    bounds.removeFromTop(60);

    int sliderX = 20;
    int sliderY = 80;
    int sliderWidth = 80;
    int sliderHeight = 140;
    int spacing = 190;

    // Input section
    inputGainSlider->setBounds(sliderX, sliderY, sliderWidth, sliderHeight);
    driveSlider->setBounds(sliderX + spacing / 2, sliderY, sliderWidth, sliderHeight);

    // Tone section
    toneSlider->setBounds(sliderX + spacing, sliderY, sliderWidth, sliderHeight);

    // EQ section
    bassSlider->setBounds(sliderX + spacing * 2, sliderY, sliderWidth, sliderHeight);
    midSlider->setBounds(sliderX + spacing * 2 + spacing / 2, sliderY, sliderWidth, sliderHeight);
    trebleSlider->setBounds(sliderX + spacing * 3, sliderY, sliderWidth, sliderHeight);
    presenceSlider->setBounds(sliderX + spacing * 3 + spacing / 2, sliderY, sliderWidth, sliderHeight);

    // Dynamics section
    compThresholdSlider->setBounds(sliderX + spacing * 4, sliderY, sliderWidth, sliderHeight);
    compRatioSlider->setBounds(sliderX + spacing * 4 + spacing / 2, sliderY, sliderWidth, sliderHeight);

    // Output section
    outputGainSlider->setBounds(sliderX + spacing * 5, sliderY, sliderWidth, sliderHeight);

    // Second row: reverb + cabinet IR
    int row2Y = 340;
    reverbRoomSlider->setBounds(sliderX, row2Y, sliderWidth, sliderHeight);
    reverbWidthSlider->setBounds(sliderX + spacing / 2, row2Y, sliderWidth, sliderHeight);
    reverbWetSlider->setBounds(sliderX + spacing, row2Y, sliderWidth, sliderHeight);
    reverbDrySlider->setBounds(sliderX + spacing + spacing / 2, row2Y, sliderWidth, sliderHeight);

    loadIRButton->setBounds(450, row2Y, 110, 28);
    clearIRButton->setBounds(570, row2Y, 70, 28);
    irNameLabel->setBounds(450, row2Y + 36, 300, 24);
}
