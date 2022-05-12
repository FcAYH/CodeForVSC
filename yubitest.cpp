void Object::Update(float dt)
{
    Vector3 direction = new Vector3(destination - position);
    direction = driection.Normalize();

    position = position + direction * 2 * Time.deltaTime;
}

bool IsPlayerInVisionCone(const vec &ai_position, const vec &ai_direction, const vec &player_position)
{
    vec direction = player_position - ai_position;

    // check if player is within distance;
    bool withinDistance = false;
    if (vec_length(direction) <= MAX_VISION_DISTANCE)
        withinDistance = true;

    // check if palyer is within angle;
    bool withAngle = false;
    float angleCos = vec_dot(direction, ai_direction) / vec_length(direction) / vec_length(ai_direction);
    float degree = acos(angleCos);
    if (degree <= MAX_VISION_ANGLE)
        withAngle = true;

    return withAngle && withinDistance;
}

bool IsBulletNearMiss(const vec &ai_position, const vec &ai_direction, const vec &bullet_origin, const vec &bullet_direction)
{
    // 先判断方向，如果方向都没向着玩家，必然false
    vec direction = bullet_direction - ai_position;
    if (vec_dot(direction, bullet_direction) < 0)
        return false;

    vec anotherPoint = bullet_origin + bullet_direction;
    float A, B, C;
    A = anotherPoint.y - bullet_origin.y;
    B = anotherPoint.x - bullet_origin.x;
    C = anotherPoint.x * bullet_origin.y + anotherPoint.y * bullet_origin.x;

    float distance = 0;
    distance = abs(A * ai_position.x + B * ai_position.y + C) / sqrt(A * A + B * B);
    if (distance <= NEAR_MISS_DISTANCE)
    {
        return true;
    }

    return false;
}
