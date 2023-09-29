#include <stdlib.h>
#include <stdio.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>

int main() {
  AVFormatContext *formatContext = NULL;
  if (avformat_open_input(&formatContext, "beauty.mp3", NULL, NULL) != 0) {
    printf("Failed to open a file\n");
    return -1;
  }
  
  if (avformat_find_stream_info(formatContext, NULL) < 0) {
    printf("Failed to find stream info\n");
    return -1;
  }
  
  int audio_stream_index = av_find_best_stream(formatContext, AVMEDIA_TYPE_AUDIO, -1, -1, NULL, 0);
  if (audio_stream_index < 0) {
    printf("Failed to find best stream\n");
    return -1; 
  }
  
  
  return 0;
}
