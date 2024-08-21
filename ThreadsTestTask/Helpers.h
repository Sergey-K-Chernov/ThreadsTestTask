#pragma once

void delay(const unsigned int milliseconds);

void delay_sleep(const unsigned int milliseconds);

// Проще было написать, чем уточнять, какой вариант ожидания требуется в задании
void delay_busy_loop(const unsigned int milliseconds);