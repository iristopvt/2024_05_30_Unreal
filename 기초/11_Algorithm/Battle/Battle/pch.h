#pragma once

#include <iostream>
#include <vector>

using namespace std;

// �̸������ϵ� ���
// pch.h / pch.cpp ����
// pch.cpp #include "pch.h"
// pch.cpp�� �Ӽ�-> c/c++ -> �̸������ϵ� ��� �����/pch.h
// ������Ʈ �Ӽ�-> c/c++ -> �̸������ϵ� ��� ���/pch.h

// ����ȭ ������ ��
// ������Ʈ �Ӽ� -> VC++���丮 -> ���Ե��丮 ���� -> $(ProjectDir) ����

#include "Contents/Creature/Creature.h"
#include "Contents/Creature/Player.h"
#include "Contents/Creature/Monster.h"

#include "Contents/Creature/Knight.h"
#include "Contents/Creature/Archer.h"

#include "Contents/World/World.h"