<h1 align="center">Anne Pro 2 Keymap</h1>

Since October 2021, I have used a [Anne Pro 2 60%](http://en.obins.net/anne-pro2/) ([C18 revision, HT32F52352 LQFP64](https://openannepro.github.io/ap2_revisions/#case)) with [Kailh BOX White switches](https://www.kailh.net/products/kailh-box-switch-set?variant=43650946826482) for my home setup.  I have used this keyboard in QWERTY throughout this time.  However, in early January 2026, I decided to switch to a [slightly modified Colemak DH for ANSI](https://colemakmods.github.io/mod-dh/keyboards.html#ansi-keyboards).

## Keymap

The keymap is detailed in [`keymap.c`](./keymap.c).  This was initially compiled using [QMK CLI v1.1.8](https://github.com/qmk/homebrew-qmk/tree/e4d46a44), [QMK Firmware v0.31.7](https://github.com/qmk/qmk_firmware/tree/0.31.7) and [AnnePro Tools v0.1.1](https://github.com/OpenAnnePro/AnnePro2-Tools/tree/3b692e82).

## Set Up

In order to reproduce the present keymap for the Anne Pro 2, you require some software that enables compilation and flashing of the keymap.

### QMK

[QMK](https://qmk.fm/) allows you to compile firmware for keyboards with custom keymaps.  To install this, run:

```commandline
$ just setup-qmk
```

This will take some time.

### Anne Pro 2 Tools

While QMK supports compilation of firmware for AP2, it does not yet support flashing it.  To flash it, we will need an [auxiliary tool](https://github.com/OpenAnnePro/AnnePro2-Tools).  You can install this using:

```commandline
$ just setup-ap2-tools
```

You may also be able to use [`dfu-util`](https://github.com/Stefan-Schmidt/dfu-util) [[ref](https://github.com/ah-/anne-key/blob/a71734f/README.md#dfu-util)], but I have not done so.

## Writing the Keymap to Keyboard

### Generating, Editing, and Compiling the Keymap

Now that `qmk` is installed, generate the keymap:

```commandline
$ just gen
```

The keyboard name and keymap are specified in the [`justfile`](./justfile).  For now, these are set to `annepro2` and `colemak` respectively.  The supported keyboards are listed in:

```commandline
$ qmk list-keyboards
```

The keymap name is arbitrarily chosen.  Now, the keymap (in its current state) should be defined in:

```commandline
~/qmk_firmware/keyboards/annepro2/keymaps/colemak/keymap.c
```

Edit this with to your heart's content.  Then, you will need to compile this into the firmware that is used for flashing:

```commandline
$ just compile
```

In the next step, we will flash this firmware onto the keyboard.

### Flashing the Anne Pro 2

In order to [flash your device](https://docs.qmk.fm/newbs_flashing#flash-your-keyboard-from-the-command-line), you must first put it into flashing mode.  To do this, you can unplug your device, hold <kbd>ESC</kbd>, and plug it back in.  Now it should be in flashing mode and take no user input.  Once this is done, simply run:

```commandline
$ just flash
```

## License

This keymap source code is released under the MIT License.  However, when compiled with QMK or OpenAnnePro software, the resulting firmware is subject to the GPL-2.0 license of that software, as per [`qmk.fm/license`](https://qmk.fm/license).
