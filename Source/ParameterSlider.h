/*
  ==============================================================================

    ParameterSlider.h
    Created: 5 Mar 2016 4:14:53pm

  ==============================================================================
*/

#ifndef PARAMETERSLIDER_H_INCLUDED
#define PARAMETERSLIDER_H_INCLUDED

// (Taken from the JUCE demo plugin PluginEditor.cpp)

//==============================================================================
// This is a handy slider subclass that controls an AudioProcessorParameter
// (may move this class into the library itself at some point in the future..)
class ParameterSlider   : public Slider,
                          private Timer
{
public:
    ParameterSlider (AudioProcessorParameter& p)
        : Slider (p.getName (256)), param (p)
    {
        // inherit APF for APFS. override getNumSteps() use that and use something like below

        if (p.getNumSteps() > 0)
        {
            const float normStepSize = 1.0 / p.getNumSteps();
            setRange (0.0, 1.0, normStepSize);
        }
        else
            setRange (0.0, 1.0, 0.0);


        Logger::outputDebugString ((String) p.getNumSteps());



        /*if (auto apb = dynamic_cast<AudioParameterBool*>(&p)) // or set stepping
            setRange(0.0, 1.0, 1.0);

        if (auto apf = dynamic_cast<AudioParameterFloat*> (&p))
        {
            if (apf->range.interval > 0.0) {
                // 1-0 normalised step size = interval / (max - min)
                const float span = apf->range.end - apf->range.start;
                jassert (span > 0);
                const float normStep = apf->range.interval / span;
                setRange (0.0, 1.0, normStep);
            }
        }
        if (auto api = dynamic_cast<AudioParameterInt*> (&p))
        {
            if (api->range.interval > 0.0) {
                // 1-0 normalised step size = interval / (max - min)
                const float span = api->range.end - api->range.start;
                jassert (span > 0);
                const float normStep = api->range.interval / span;
                setRange (0.0, 1.0, normStep);
            }
            api->
        }*/

        /*String out;
        out << getMaximum() << " " << getMinimum() << " " << getInterval();
        Logger::outputDebugString(out);*/

        startTimerHz (30);
        updateSliderPos();
    }

    void valueChanged() override
    {
        param.setValueNotifyingHost ((float) Slider::getValue());
    }

    void timerCallback() override       { updateSliderPos(); }

    void startedDragging() override     { param.beginChangeGesture(); }
    void stoppedDragging() override     { param.endChangeGesture();   }

    double getValueFromText (const String& text) override   { return param.getValueForText (text); }
    String getTextFromValue (double value) override         { return param.getText ((float) value, 1024); }

    void updateSliderPos()
    {
        const float newValue = param.getValue();

        if (newValue != (float) Slider::getValue() && ! isMouseButtonDown())
            Slider::setValue (newValue);
    }

    AudioProcessorParameter& param;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ParameterSlider)
};


#endif  // PARAMETERSLIDER_H_INCLUDED
