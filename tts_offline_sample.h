#ifndef TTS_OFFLINE_SAMPLE_H
#define TTS_OFFLINE_SAMPLE_H
#ifdef __cplusplus
extern "C" {
#endif

int text_to_speech(const char* src_text, const char* des_path, const char* params);
int TTS(const char * str);

#ifdef __cplusplus
}
#endif

#endif // TTS_OFFLINE_SAMPLE_H
