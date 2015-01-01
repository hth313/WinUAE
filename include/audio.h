 /*
  * UAE - The Un*x Amiga Emulator
  *
  * Sound emulation stuff
  *
  * Copyright 1995, 1996, 1997 Bernd Schmidt
  */

#define PERIOD_MAX ULONG_MAX
#define MAX_EV ~0u

extern void aud0_handler (void);
extern void aud1_handler (void);
extern void aud2_handler (void);
extern void aud3_handler (void);

extern void AUDxDAT (int nr, uae_u16 value);
extern void AUDxDAT (int nr, uae_u16 value, uaecptr addr);
extern void AUDxVOL (int nr, uae_u16 value);
extern void AUDxPER (int nr, uae_u16 value);
extern void AUDxLCH (int nr, uae_u16 value);
extern void AUDxLCL (int nr, uae_u16 value);
extern void AUDxLEN (int nr, uae_u16 value);

extern uae_u16 audio_dmal (void);
extern void audio_state_machine (void);
extern uaecptr audio_getpt (int nr, bool reset);

extern int init_audio (void);
extern void ahi_install (void);
extern void audio_reset (void);
extern void update_audio (void);
extern void audio_evhandler (void);
extern void audio_hsync (void);
extern void audio_update_adkmasks (void);
extern void update_sound (double clk);
extern void led_filter_audio (void);
extern void set_audio (void);
extern int audio_activate (void);
extern void audio_deactivate (void);
extern void audio_vsync (void);

extern void audio_sampleripper(int);
extern int sampleripper_enabled;
extern void write_wavheader (struct zfile *wavfile, uae_u32 size, uae_u32 freq);

extern void audio_update_sndboard(unsigned int);
extern void audio_enable_sndboard(bool);
extern void audio_state_sndboard(int);
extern void audio_state_sndboard_state(int, int, unsigned int);

extern void audio_update_cda(unsigned int);
extern void audio_enable_cda(bool);
extern void audio_state_cda(int);
extern void audio_state_cda_state(int, int, unsigned int);

#define AUDIO_CHANNELS_PAULA 4
#define AUDIO_CHANNELS_MAX 8
#define AUDIO_CHANNEL_SNDBOARD_LEFT 4
#define AUDIO_CHANNEL_SNDBOARD_RIGHT 5
#define AUDIO_CHANNEL_CDA_LEFT 6
#define AUDIO_CHANNEL_CDA_RIGHT 7

enum {
    SND_MONO, SND_STEREO, SND_4CH_CLONEDSTEREO, SND_4CH, SND_6CH_CLONEDSTEREO, SND_6CH, SND_NONE };
STATIC_INLINE int get_audio_stereomode (int channels)
{
    switch (channels)
    {
	case 1:
	return SND_MONO;
	case 2:
	return SND_STEREO;
	case 4:
	return SND_4CH;
	case 6:
	return SND_6CH;
    }
    return SND_STEREO;
}
STATIC_INLINE int get_audio_nativechannels (int stereomode)
{
    int ch[] = { 1, 2, 4, 4, 6, 6, 0 };
    return ch[stereomode];
}
STATIC_INLINE int get_audio_amigachannels (int stereomode)
{
    int ch[] = { 1, 2, 2, 4, 2, 4, 0 };
    return ch[stereomode];
}
STATIC_INLINE int get_audio_ismono (int stereomode)
{
    if (stereomode == 0)
	return 1;
    return 0;
}

 #define SOUND_MAX_DELAY_BUFFER 1024
 #define SOUND_MAX_LOG_DELAY 10
 #define MIXED_STEREO_MAX 16
 #define MIXED_STEREO_SCALE 32
