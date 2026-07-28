#include <juce_gui_extra/juce_gui_extra.h>
#include "PluginProcessor.h"
#include "PluginEditor.h"

MantraAudioProcessorEditor::MantraAudioProcessorEditor(MantraAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
    setLookAndFeel(&mantraLnf);

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
    irNameLabel->setColour(juce::Label::textColourId, juce::Colour(0xff9a9aa4));

    for (auto* label : { inputGainLabel.get(), driveLabel.get(), toneLabel.get(), bassLabel.get(),
                         midLabel.get(), trebleLabel.get(), presenceLabel.get(), compThresholdLabel.get(),
                         compRatioLabel.get(), outputGainLabel.get(), reverbRoomLabel.get(),
                         reverbWidthLabel.get(), reverbWetLabel.get(), reverbDryLabel.get() })
    {
        label->setJustificationType(juce::Justification::centred);
        label->setFont(juce::Font(juce::FontOptions(13.0f)));
    }

    // Must come after the sliders exist — setSize() synchronously calls resized()
    setSize(1020, 496);
}

MantraAudioProcessorEditor::~MantraAudioProcessorEditor()
{
    setLookAndFeel(nullptr);
}

namespace
{
    struct Section { juce::Rectangle<int> panel; const char* title; };

    const Section kSections[] = {
        {{ 10,  52, 192, 194}, "INPUT"},
        {{212,  52, 100, 194}, "TONE"},
        {{322,  52, 376, 194}, "EQ"},
        {{708,  52, 192, 194}, "DYNAMICS"},
        {{910,  52, 100, 194}, "OUTPUT"},
        {{ 10, 286, 376, 194}, "REVERB"},
        {{396, 286, 614, 194}, "CABINET IR"},
    };
}

void MantraAudioProcessorEditor::paint(juce::Graphics& g)
{
    auto bounds = getLocalBounds().toFloat();

    // Faceplate: vertical gradient with a soft amber glow behind the title
    g.setGradientFill(juce::ColourGradient(juce::Colour(0xff1a1a20), 0.0f, 0.0f,
                                           juce::Colour(0xff101014), 0.0f, bounds.getBottom(), false));
    g.fillRect(bounds);

    g.setGradientFill(juce::ColourGradient(MantraLookAndFeel::amber.withAlpha(0.12f),
                                           bounds.getCentreX(), 0.0f,
                                           juce::Colours::transparentBlack,
                                           bounds.getCentreX(), 110.0f, true));
    g.fillRect(bounds.withHeight(110.0f));

    // Title
    g.setColour(MantraLookAndFeel::amber);
    g.setFont(juce::Font(juce::FontOptions(26.0f, juce::Font::bold)).withExtraKerningFactor(0.3f));
    g.drawText("MANTRA", getLocalBounds().removeFromTop(48), juce::Justification::centred, false);

    g.setColour(MantraLookAndFeel::amber.withAlpha(0.25f));
    g.fillRect(30, 24, getWidth() / 2 - 130, 1);
    g.fillRect(getWidth() / 2 + 100, 24, getWidth() / 2 - 130, 1);

    // Section panels
    for (const auto& s : kSections)
    {
        auto r = s.panel.toFloat();
        g.setColour(MantraLookAndFeel::panelFill);
        g.fillRoundedRectangle(r, 8.0f);
        g.setColour(MantraLookAndFeel::panelOutline);
        g.drawRoundedRectangle(r.reduced(0.5f), 8.0f, 1.0f);

        g.setColour(MantraLookAndFeel::textDim);
        g.setFont(juce::Font(juce::FontOptions(13.0f, juce::Font::bold)).withExtraKerningFactor(0.15f));
        g.drawText(s.title, s.panel.withHeight(20).translated(0, 5), juce::Justification::centred, false);
    }

    // Corner screws
    auto drawScrew = [&g](float cx, float cy)
    {
        juce::Rectangle<float> screw(cx - 5.0f, cy - 5.0f, 10.0f, 10.0f);
        g.setColour(juce::Colour(0xff34343c));
        g.fillEllipse(screw);
        g.setColour(juce::Colour(0xff55555e));
        g.drawEllipse(screw, 1.0f);
        g.setColour(juce::Colour(0xff15151a));
        g.drawLine(cx - 3.0f, cy + 3.0f, cx + 3.0f, cy - 3.0f, 1.5f);
    };
    drawScrew(16.0f, 16.0f);
    drawScrew((float)getWidth() - 16.0f, 16.0f);
    drawScrew(16.0f, (float)getHeight() - 16.0f);
    drawScrew((float)getWidth() - 16.0f, (float)getHeight() - 16.0f);
}

void MantraAudioProcessorEditor::resized()
{
    const int knobW = 80, knobH = 140;
    const int row1Y = 96, row2Y = 330;

    // Row 1: input | tone | EQ | dynamics | output (positions match kSections panels)
    inputGainSlider->setBounds(20, row1Y, knobW, knobH);
    driveSlider->setBounds(112, row1Y, knobW, knobH);

    toneSlider->setBounds(222, row1Y, knobW, knobH);

    bassSlider->setBounds(332, row1Y, knobW, knobH);
    midSlider->setBounds(424, row1Y, knobW, knobH);
    trebleSlider->setBounds(516, row1Y, knobW, knobH);
    presenceSlider->setBounds(608, row1Y, knobW, knobH);

    compThresholdSlider->setBounds(718, row1Y, knobW, knobH);
    compRatioSlider->setBounds(810, row1Y, knobW, knobH);

    outputGainSlider->setBounds(920, row1Y, knobW, knobH);

    // Row 2: reverb | cabinet IR
    reverbRoomSlider->setBounds(20, row2Y, knobW, knobH);
    reverbWidthSlider->setBounds(112, row2Y, knobW, knobH);
    reverbWetSlider->setBounds(204, row2Y, knobW, knobH);
    reverbDrySlider->setBounds(296, row2Y, knobW, knobH);

    loadIRButton->setBounds(416, 350, 110, 30);
    clearIRButton->setBounds(536, 350, 70, 30);
    irNameLabel->setBounds(416, 396, 560, 24);
}
