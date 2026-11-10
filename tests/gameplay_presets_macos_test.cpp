#include "ui/macos_gameplay_presets.h"
#include <cassert>
namespace oot::renderer { void apply_lighting(const LightingValues&) {} }
int main() {
    using namespace oot::ui;
    for (int preset = 0; preset < 3; ++preset) {
        Settings s;
        s.volume_percent = 37;
        s.texture_pack = 2;
        lighting::Lighting l;
        l.bounce = l.glow = l.haze = l.indoor_dust = l.outdoor_dust = l.window_shafts = 2;
        assert(macos::gameplay_preset(preset, s, l));
        assert(s.volume_percent == 37 && s.texture_pack == 2);
        assert(s.texture_detail == 2 && s.frame_rate == 0 && s.downsampling == 0);
        assert(s.resolution == (preset == 2 ? 4 : 2));
        assert(lighting::values_of(l).level == 2);
        assert(lighting::values_of(l).occlusion_samples == (preset == 0 ? 4 : 2));
        assert(s.antialiasing == (preset == 0 ? 2 : 1));
        const auto original_s = s; const auto original_l = l;
        assert(macos::gameplay_preset(preset, s, l));
        assert(s.volume_percent == original_s.volume_percent && l == original_l);
        assert(!macos::gameplay_preset(-1, s, l));
        assert(!macos::gameplay_preset(3, s, l));
        assert(s.resolution == original_s.resolution && l == original_l);
    }
}
