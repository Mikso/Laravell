@extends('site.home.templates.templateSuporte')

@section('content')
<br><br><br>

<h1 class="title-pg">GESTÃO DE EQUIPE</h1>

<form class="form" action="{{ route('suporte.store') }}" method="POST">
       <input type="hidden" name="_token" value="{{ csrf_token() }}">
 
      <div class="form-group">
        <label for="nome">Nome</label>
        <input type="text" id="nome" name="nome" class="form-control" placeholder="Nome">
      </div>
 
      <div class="form-group">
        <label for="email">E-Mail</label>
        <input type="text" id="email" name="email" class="form-control" placeholder="E-Mail">
      </div>
 
      <div class="form-group">
        <textarea id="mensagem" name="mensagem" class="form-control" placeholder="Digite sua mensagem"></textarea>
      </div>
 
      <button type="submit" class="btn btn-success">Enviar</button>
 
    </form>



@endsection