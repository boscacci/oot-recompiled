#pragma once
#include "ui/ui_settings.h"
#include "ui/ui_lighting.h"

namespace oot::ui::macos {
// Explicit choices, never hardware guesses or automatic changes to existing profiles.
inline bool gameplay_preset(int preset, Settings& s, lighting::Lighting& l) {
    if (preset < 0 || preset > 2) return false;
    s.window_mode = 1;
    s.resolution = preset == 2 ? 4 : 2;
    s.downsampling = 0;
    s.aspect = 1;
    s.antialiasing = preset == 0 ? 2 : 1;
    s.frame_rate = 0;
    s.texture_detail = 2;
    s.render_distance = 0;
    l.raytracing = 1;
    l.shadows = 1;
    l.occlusion = 1;
    l.occlusion_quality = preset == 0 ? 0 : 3;
    l.lights = 1;
    // These effects require level 3. Leave level 2 selectable without a CLI override.
    l.bounce = l.reflections = l.glow = l.haze = 0;
    l.indoor_dust = l.outdoor_dust = l.window_shafts = 0;
    l.inspect = l.experiment = 0;
    return true;
}
}
