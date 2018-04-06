<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class Contato extends Model
{
   
    public function up()
    {
        Schema::create('contatos', function (Blueprint $table) {
            $table->increments('id');
            $table->string('nome');
            $table->string('email');
            $table->text('mensagem');
            $table->timestamps();
        });
    }




public function down()
    {
        Schema::drop('contatos');
    }

}
