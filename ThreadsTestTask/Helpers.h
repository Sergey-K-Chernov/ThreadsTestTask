#pragma once

void delay(const unsigned int milliseconds);

void delay_sleep(const unsigned int milliseconds);

// ����� ���� ��������, ��� ��������, ����� ������� �������� ��������� � �������
void delay_busy_loop(const unsigned int milliseconds);