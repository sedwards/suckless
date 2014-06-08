#include <alsa/asoundlib.h>
#include <alsa/control.h>

int
get_vol(void)
{
    long int vol;
    snd_hctl_t *hctl;
    snd_ctl_elem_id_t *id;
    snd_ctl_elem_value_t *control;

// To find card and subdevice: /proc/asound/, aplay -L, amixer controls
    snd_hctl_open(&hctl, "hw:0", 0);
    snd_hctl_load(hctl);

    snd_ctl_elem_id_alloca(&id);
    snd_ctl_elem_id_set_interface(id, SND_CTL_ELEM_IFACE_MIXER);

// amixer controls
    snd_ctl_elem_id_set_name(id, "Master Playback Volume");

    snd_hctl_elem_t *elem = snd_hctl_find_elem(hctl, id);

    snd_ctl_elem_value_alloca(&control);
    snd_ctl_elem_value_set_id(control, id);

    snd_hctl_elem_read(elem, control);
    vol = snd_ctl_elem_value_get_integer(control,0);

    snd_hctl_close(hctl);
    return (int)vol;
}
