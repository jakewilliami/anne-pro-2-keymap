# -*- mode: just -*-

# QMK specifications
keyboard := "annepro2/c15"  # qmk list-keyboards | grep annepro2
keymap := "colemak"

# QMK dependencies
brew_dir := "/opt" / "homebrew" / "opt"
avr_gcc := brew_dir / "avr-gcc@8" / "bin"
arm_none_eabi_gcc := brew_dir / "arm-none-eabi-gcc@8" / "bin"
arm_none_eabi_binutils := brew_dir / "arm-none-eabi-binutils" / "bin"
qmk_path_additions := avr_gcc + ":" + arm_none_eabi_gcc + ":" + arm_none_eabi_binutils
annepro2_tools_repo := "https://github.com/OpenAnnePro/AnnePro2-Tools.git"
annepro2_tools_rev := "618f2e4"
annepro2_tools_base_dir := "/tmp/x3/_b5wkv6d2k707z2m57sdc1h80000gn/T/tmp.ecoodEFK1F"  # static generated name with mktemp
annepro2_tools_dir := annepro2_tools_base_dir / "AnnePro2-Tools"
annepro2_tools := annepro2_tools_dir / "target" / "release"
flashing_path_additions := qmk_path_additions + ":" + annepro2_tools

# Compile firmware for new keymap
[macos]
compile:
    PATH="{{qmk_path_additions}}:$PATH" qmk compile -kb {{keyboard}} -km {{keymap}}

# Generate a new keymap
[macos]
gen:
    PATH="{{flashing_path_additions}}:$PATH" qmk new-keymap -kb {{keyboard}} -km {{keymap}}

# Flash compiled keymap to keyboard (ensure it is in flashing mode!)
[macos]
flash:
    #!/usr/bin/env bash
    if [[ ! -e {{annepro2_tools_dir}} ]]; then
        echo "ERROR: flashing utility for AP2 not found" >&2
        exit 1
    fi
    # NOTE: the keyboard MUST be in flashing mode for this to work
    PATH="{{flashing_path_additions}}:$PATH" qmk flash -kb {{keyboard}} -km {{keymap}}

# Install project dependencies
[macos]
setup-qmk:
    brew install qmk/qmk/qmk
    brew install dos2unix
    PATH="{{qmk_path_additions}}:$PATH" qmk setup

# Install community Anne Pro 2 flashing tool dependency
[macos]
setup-ap2-tools:
    #!/usr/bin/env bash
    # NOTE: this recipe assumes you have Rust installed
    mkdir -p {{annepro2_tools_base_dir}}
    if [[ ! -e {{annepro2_tools_dir}} ]]; then
        git clone {{annepro2_tools_repo}} {{annepro2_tools_dir}}
        cd {{annepro2_tools_dir}}
        git checkout {{annepro2_tools_rev}}
        cargo build --release
    fi
