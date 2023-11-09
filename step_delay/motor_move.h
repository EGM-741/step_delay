void M_move(byte motor_1,byte motor_2,signed direction)
{
    if (direction == 1)
    {
        digitalWrite(motor_1,1);
        digitalWrite(motor_2,0);
    }
    else if (direction == -1)
    {
        digitalWrite(motor_1,0);
        digitalWrite(motor_2,1);
    }
    else {
        digitalWrite(motor_1,0);
        digitalWrite(motor_2,0);
    }
}