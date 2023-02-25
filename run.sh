miral_server=build/bin/compositor
bindir=$(dirname $0)
if [ "${bindir}" != "" ]; then bindir="${bindir}/"; fi
terminal=${bindir}miral-terminal

# If there's already a compositor for WAYLAND_DISPLAY let Mir choose another
if [ -O "${XDG_RUNTIME_DIR}/${WAYLAND_DISPLAY}" ]
then
    unset WAYLAND_DISPLAY
fi

echo $bindir
MIR_SERVER_ENABLE_X11=1 MIR_SERVER_SHELL_TERMINAL_EMULATOR=${terminal} exec ${bindir}${miral_server} $*