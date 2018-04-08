<?php

namespace App\Model\Signup;

use Illuminate\Database\Eloquent\Model;

class Usuario extends Model
{
    protected $table = 'usuario';


    protected $fillable =[
        'nome', 'sobrenome', 'idade', 'cpf', 'cep', 'email', 'password'
    ];

}
