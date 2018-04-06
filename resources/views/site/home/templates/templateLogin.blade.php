<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
  
	<title>{{ $titulo or 'Login' }}</title>

    <link rel="stylesheet" href="{{ url('css/assets/css/bootstrap.css') }}">
    <script src="{{ url('css/assets/js/jquery.js') }}"></script>
    <script src="{{ url('css/assets/js/bootstrap.js')}}"></script>

</head>
<body>


<header style="padding-top:50px; padding-bottom:30px">
        <nav class="navbar navbar-fixed-top" style="padding-left:0px; padding-right:20px; background-color: navy; ">

            <div class="navbar-header">
                <a class="navbar-brand" href="#"></a>
            </div>
            <ul class="nav navbar-nav">
                <li><a href="{{ url('/') }}">Página Inicial</a></li>
                <li><a href="{{ url('alpha-imoveis/como-funciona') }}">Como funciona</a></li>
                <li><a href="#">Suporte</a></li>
            </ul>
            <ul class="nav navbar-nav navbar-right">
                <li><a href="{{ url('alpha-imoveis/signup') }}"><span class="glyphicon glyphicon-user"></span> Sign Up</a></li>
             
            </ul>

        </nav>

</header>


    <div class="container" style="padding-top: 20px; padding-bottom: 20px; width: 30%">


      <form action="servidor/logado.php" method="post">
        <h2 class="form-signin-heading">Acesse sua conta</h2>
        <label>Email address</label>
        <input type="email" name="email" class="form-control" placeholder="Email address" required autofocus>
        <br>
        <label>Password</label>
        <input type="password" name="senha" class="form-control" placeholder="Password" required><br>
       
    <div class="text-center">
        <button type="submit" class="btn btn-success" style="width: 50%">Login</button>

    </div>



      </form>

  
<br>
  
        </div>


</body>
</html>